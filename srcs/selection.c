/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:22:20 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/10 11:33:02 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_num(t_stack *stack)
{
	t_dlist *temp;
	int 	small;
	
	temp = stack->head;
	small = stack->head->pos;
	while (temp)
	{
		if (small > temp->pos)
			small = temp->pos;
		temp = temp->next;
	}
	return (small);
}

int	biggest_num(t_stack *stack)
{
	t_dlist *temp;
	int 	big;
	
	temp = stack->head;
	big = stack->head->pos;
	while (temp)
	{
		if (big < temp->pos)
			big = temp->pos;
		temp = temp->next;
	}
	return (big);
}

void	direction(t_stack *stack, int len, int small)
{
	t_dlist *temp;
	int i;

	i = 0;
	temp = stack->head;
	while (temp->next)
	{
		i++;
		temp = temp->next;
		if (temp->pos == small)
			break;
	}
	if (i < (len / 2))
		rotate(stack, "ra");
	else
		reverse_rotate(stack, "rra");
}

void selectionSort(t_stacks *s, int len)
{
	int small;
	int big;

	if (is_sorted(s->stack_a->head) != true)
	{	
		while (dlst_len(s->stack_a->head) > 3)
		{
			small = smallest_num(s->stack_a);
			if (is_in_order(s->stack_a->head, 1) != dlst_len(s->stack_a->head))
			{
				while (s->stack_a->head->pos != small)
					direction(s->stack_a, len, small);
			}
			push(s->stack_a, s->stack_b, "pb");
		}
		big = biggest_num(s->stack_a);
		if (s->stack_a->head->pos == big)
			rotate(s->stack_a, "ra");
		else if (s->stack_a->head->next->pos == big)
			reverse_rotate(s->stack_a, "rra");
		if (is_in_order(s->stack_a->tail, 1) != 3)
			swap(s->stack_a, "sa");
		while (s->stack_b->head != NULL)
			push(s->stack_b, s->stack_a, "pa");
	}
}