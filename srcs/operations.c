/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:43:36 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/20 18:17:48 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_dlist	*swap_a(t_dlist *head)
{
	t_dlist *temp;
	
	temp = head->next;
	head->next = temp->next;
	head->prev = temp->prev;
	temp->prev = NULL;
	temp->next = head;
	head = temp;
	return (head);
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
	stackA->tail->prev = NULL;
	stackA->tail->next = stackA->head;
	stackA->head->prev = stackA->tail;
	stackA->head = stackA->tail;
	stackA->tail = temp;
	return(stackA);
}

t_stacks	*push_b(t_stacks *stacks)
{
	/* t_dlist *temp;
 */
	stacks->stackB->head = stacks->stackA->head;
	if (stacks->stackB->tail == NULL)
		stacks->stackB->tail = stacks->stackA->head;
	return (stacks);
}
