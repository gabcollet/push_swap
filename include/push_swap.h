/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:57:49 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/30 11:48:04 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
#include <stdio.h> //fonction interdit

typedef struct		s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_stack
{
	struct s_dlist	*head;
	struct s_dlist	*tail;
}					t_stack;

typedef struct		s_stacks
{
	struct s_stack	*stackA;
	struct s_stack	*stackB;
}					t_stacks;

/* main.c */
void		create_dlist(t_stack *stackA, char **argv);
int			main(int argc, char **argv);

/* utils.c */
void		ft_isnum(char *str);
void		check_duplicate(char **argv, int i);
t_stacks	*initialise_stacks();
void		clear_stacks(t_stacks *stacks);

/* dbl_list_lib.c */
t_dlist		*dlst_last(t_dlist *lst);
t_dlist		*dlst_new(int content);
void		dlst_add_front(t_dlist **head, t_dlist *new);
void		dlst_add_back(t_dlist **head, t_dlist *new);
void		dlst_clear(t_stack *stackA);

/* dbl_list_print.c */
void		dlst_print(t_stacks *stacks);
void		dlst_reverseprint(t_dlist *head);

/* operations.c */
t_stack		*swap_a(t_stack *stack);
t_stack		*rotate_a(t_stack *stackA);
t_stack		*reverse_rotate_a(t_stack *stackA);
t_stacks	*push_b(t_stacks *stacks);

#endif
