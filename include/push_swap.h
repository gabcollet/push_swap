/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:57:49 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/10 15:51:51 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"
#include <stdio.h> //fonction interdit

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
	int				pos;
}					t_dlist;

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

int moves; //global value *****

/* main.c */
int			assign_pos(int len, int i, t_dlist *lst);
void		create_dlist(t_stack *stack_a, char **argv);
int			is_sorted(t_dlist *lst);
int			is_in_order(t_dlist *lst, int i);
int			main(int argc, char **argv);

/* utils.c */
void		error(void);
void		ft_isint(char *str);
void		check_duplicate(char **argv, int i);
t_stacks	*initialise_stacks(void);
void		clear_stacks(t_stacks *stacks);

/* dbl_list_lib.c */
t_dlist		*dlst_last(t_dlist *lst);
int			dlst_len(t_dlist *lst);
t_dlist		*dlst_new(int content);
void		dlst_add_front(t_dlist **head, t_dlist *new);
void		dlst_add_back(t_dlist **head, t_dlist *new);
void		dlst_clear(t_stack *stack_a);

/* dbl_list_print.c */ //fonction à enlever
void		dlst_print(t_stacks *stacks);
void		dlst_reverseprint(t_dlist *head);
char		*take_command(t_stacks *stacks, char *str);

/* operations.c */
void		swap(t_stack *stack, char *str);
void		rotate(t_stack *stack, char *str);
void		reverse_rotate(t_stack *stack, char *str);
void		push(t_stack *src, t_stack *dest, char *str);
void		push1(t_stack *src, t_stack *dest);

/* quicksort.c */
void		skip_order(t_stack *s, int order, int i);
void		swap_both(t_stacks *s);
void		quicksort(t_stacks *stacks, int len);
void		move_a_to_b(t_stacks *stacks, int len, int order);
void		move_b_to_a(t_stacks *stacks, int len, int order);
int			find_median(t_dlist *lst);

/* radix.c */
int			power(int n, int ex);
void    	sort_radix(t_stack *a, t_stack *b, int len);

/* selection.c */
int			smallest_num(t_stack *stack);
int			biggest_num(t_stack *stack);
void		direction(t_stack *stack, int len, int small, int x);
void		selectionsort_a(t_stacks *s, int len);
void		selectionsort_b(t_stacks *s, int len);

#endif
