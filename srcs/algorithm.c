/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:31:02 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/08 11:48:10 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stacks *stacks)
{
	int	len;
	int pivot;
	int order;

	pivot = find_median(stacks->stack_a->head);
	len = dlst_len(stacks->stack_a->head);
	order = is_in_order(stacks->stack_a->tail, 1);
	if (order != 1)
		len = len - order;
	while (len-- && stacks->stack_a->head->next)
	{
		if (stacks->stack_a->head->pos >= pivot && stacks->stack_a->head->next->pos >= pivot)
			rotate(stacks->stack_a, "ra");
		else
		{
			if (stacks->stack_a->head->pos > stacks->stack_a->head->next->pos)
				swap(stacks->stack_a, "sa");
			push(stacks->stack_a, stacks->stack_b, "pb");
		}
	}
	while (order-- > 0)
	{
		if (order >= dlst_len(stacks->stack_a->head))
			reverse_rotate(stacks->stack_a, "rra");
		else
			rotate(stacks->stack_a, "ra");
	}
}

void	move_b_to_a(t_stacks *stacks)
{
	int	len;
	int pivot;

	pivot = find_median(stacks->stack_b->head);
	len = dlst_len(stacks->stack_b->head);
	while (len--)
	{
		if (stacks->stack_b->head->pos <= pivot)
		{
			if (dlst_len(stacks->stack_b->head) == 1)
				push(stacks->stack_b, stacks->stack_a, "pa");
			else
				rotate(stacks->stack_b, "rb");
		}
		else
		{
			if (stacks->stack_b->head->pos < stacks->stack_b->head->next->pos)
				swap(stacks->stack_b, "sb");
			push(stacks->stack_b, stacks->stack_a, "pa");
		}
	}
}

int	find_median(t_dlist *lst)
{
	int median;
	int	len;
	
	median = 0;
	len = 0;
	while (lst)
	{
		median += lst->pos; 
		len++;
		lst = lst->next;
	}
	median /= len;
	return (median);
}
