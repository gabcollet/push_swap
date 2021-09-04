/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:31:02 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/03 20:29:56 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stacks *stacks, int pivot)
{
	int	len;

	len = dlst_len(stacks->stack_a->head);
	while (len--)
	{
		if (stacks->stack_a->head->pos >= pivot)
			rotate(stacks->stack_a);
		else
		{
			if (stacks->stack_a->head->pos > stacks->stack_a->head->next->pos)
				swap(stacks->stack_a);
			push(stacks->stack_a, stacks->stack_b);
		}
	}
	while (stacks->stack_a->head->pos != pivot)
			rotate(stacks->stack_a);
	push(stacks->stack_a, stacks->stack_b);
}

void	move_b_to_a(t_stacks *stacks, int pivot)
{
	int	len;

	len = dlst_len(stacks->stack_b->head);
	while (len--)
	{
		if (stacks->stack_b->head->pos <= pivot)
			rotate(stacks->stack_b);
		else
			push(stacks->stack_b, stacks->stack_a);
	}
	while (stacks->stack_b->head->pos != pivot)
			rotate(stacks->stack_b);
	push(stacks->stack_b, stacks->stack_a);
}

