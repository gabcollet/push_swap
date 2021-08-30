/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:43:36 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/30 16:37:20 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*swap_a(t_stack *stack)
{
	t_dlist *temp;
	
	temp = stack->head->next;
	stack->head->next = temp->next;
	stack->head->prev = temp;
	temp->prev = NULL;
	if (temp->next)
		temp->next->prev = stack->head;
	temp->next = stack->head;
	stack->head = temp;
	return (stack);
}

t_stack	*rotate_a(t_stack *stackA)
{
	t_dlist *temp;

	temp = stackA->head->next;
	stackA->head->next = NULL;
	stackA->head->prev = stackA->tail;
	temp->prev = NULL;
	stackA->tail->next = stackA->head;
	stackA->tail = stackA->head;
	stackA->head = temp;
	return (stackA);
}

t_stack	*reverse_rotate_a(t_stack *stackA)
{
	t_dlist	*temp;

	temp = stackA->tail->prev;
	temp->next = NULL;
	stackA->tail->next = stackA->head;
	stackA->head->prev = stackA->tail;
	stackA->head = stackA->tail;
	stackA->tail = temp;
	return (stackA);
}

t_stacks	*push_b(t_stacks *stacks)
{
	t_dlist *temp;

	if (stacks->stackA->head)
	{
		temp = NULL;
		if (stacks->stackA->head->next)
		{
			temp = stacks->stackA->head->next;
			temp->prev = NULL;
		}
		if (stacks->stackB->tail == NULL)
		{
			stacks->stackA->head->next = NULL;
			stacks->stackB->tail = stacks->stackA->head;
		}
		else
		{
			stacks->stackA->head->next = stacks->stackB->head;
			stacks->stackB->tail->prev = stacks->stackA->head;
		}
		stacks->stackB->head = stacks->stackA->head;
		stacks->stackB->head->prev = NULL;
		stacks->stackA->head = temp;
		if (stacks->stackA->head == NULL)
			stacks->stackA->tail = NULL;
	}
	return (stacks);
}
