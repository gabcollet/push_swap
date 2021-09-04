/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:43:36 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/04 17:49:48 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_dlist	*temp;

	if (stack->head != stack->tail && stack->head && stack->tail)
	{	
		temp = stack->head->next;
		stack->head->next = temp->next;
		stack->head->prev = temp;
		temp->prev = NULL;
		if (temp->next)
			temp->next->prev = stack->head;
		temp->next = stack->head;
		stack->head = temp;
		if (stack->tail->content == stack->head->content)
			stack->tail = stack->head->next;
	}
}

void	reverse_rotate(t_stack *stack)
{
	t_dlist	*temp;

	if (stack->head != stack->tail && stack->head && stack->tail)
	{	
		temp = stack->head->next;
		stack->head->next = NULL;
		stack->head->prev = stack->tail;
		temp->prev = NULL;
		stack->tail->next = stack->head;
		stack->tail = stack->head;
		stack->head = temp;
	}
}

void	rotate(t_stack *stack)
{
	t_dlist	*temp;

	if (stack->head != stack->tail && stack->head && stack->tail)
	{
		temp = stack->tail->prev;
		temp->next = NULL;
		stack->tail->next = stack->head;
		stack->head->prev = stack->tail;
		stack->head = stack->tail;
		stack->tail = temp;
	}
}

void	push(t_stack *src, t_stack *dest)
{
	if (src->head)
		push_i_hate_norminette(src, dest);
}

void	push_i_hate_norminette(t_stack *src, t_stack *dest)
{
	t_dlist		*temp;

	temp = NULL;
	if (src->head->next)
	{
		temp = src->head->next;
		temp->prev = NULL;
	}
	if (dest->tail == NULL)
	{
		src->head->next = NULL;
		dest->tail = src->head;
	}
	else
	{
		src->head->next = dest->head;
		dest->head->prev = src->head;
	}
	dest->head = src->head;
	dest->head->prev = NULL;
	src->head = temp;
	if (src->head == NULL)
		src->tail = NULL;
}
