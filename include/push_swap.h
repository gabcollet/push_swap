/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:57:49 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/13 10:56:28 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_stack
{
	struct s_dlist	*head;
	struct s_dlist	*tail;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_stacks;

/* main.c */
int			assign_pos(int len, int i, t_dlist *lst);
void		create_dlist(t_stack *stack_a, char **argv);
int			is_sorted(t_dlist *lst);
int			is_in_order(t_dlist *lst, int i);
int			main(int argc, char **argv);

/* utils.c */
void		error(void);
void		check_duplicate(char **argv, int i);
t_stacks	*initialise_stacks(void);
void		clear_stacks(t_stacks *stacks);

/* dbl_list_lib.c */
void		dlst_clear(t_stack *stack_a);

/* operations.c */
void		swap(t_stack *stack, char *str);
void		rotate(t_stack *stack, char *str);
void		reverse_rotate(t_stack *stack, char *str);
void		push(t_stack *src, t_stack *dest, char *str);
void		push1(t_stack *src, t_stack *dest);

/* radix.c */
int			power(int n, int ex);
void		sort_radix(t_stack *a, t_stack *b, int len);

/* selection.c */
int			smallest_num(t_stack *stack);
int			biggest_num(t_stack *stack);
void		direction(t_stack *stack, int len, int small);
void		selectionsort(t_stacks *s, int len);

#endif
