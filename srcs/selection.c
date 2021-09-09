/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:22:20 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/09 17:49:47 by gcollet          ###   ########.fr       */
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
		reverse_rotate(stack, "rra"); //rotate
}

void selectionSort(t_stacks *stacks, int len)
{
	int small;

	small = 0;
	//reste a mettre pour 1 2 3 4 5 parce que is_sorted fait bugger
	
	while (dlst_len(stacks->stack_a->head) > 3)
	{
		small = smallest_num(stacks->stack_a);
		while (stacks->stack_a->head->pos != small)
			direction(stacks->stack_a, len, small);
		push(stacks->stack_a, stacks->stack_b, "pb");
	}
	small = smallest_num(stacks->stack_a);
	if (stacks->stack_a->head->pos != small && stacks->stack_a->head->pos > stacks->stack_a->head->next->pos)
		swap(stacks->stack_a, "sa");
	if (stacks->stack_a->head->pos == small && stacks->stack_a->head->next->pos == biggest_num(stacks->stack_a))
		swap(stacks->stack_a, "sa");
	direction(stacks->stack_a, len, small);
	while (stacks->stack_b->head != NULL)
		push(stacks->stack_b, stacks->stack_b, "pa");
}