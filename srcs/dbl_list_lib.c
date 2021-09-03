/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_list_lib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:24:11 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/03 13:51:00 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_dlist	*dlst_last(t_dlist *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

int		dlst_len(t_dlist *lst)
{
	int	len;
	
	len = 0;
	if (lst)
	{
		len++;
		while (lst->next)
		{
			lst = lst->next;
			len++;
		}
	}
	return (len);
}

void	dlst_add_back(t_dlist **head, t_dlist *new)
{
	t_dlist	*temp;

	if (*head == NULL)
	{
		temp = *head;
		*head = new;
		free(temp);
	}
	else
	{
		temp = dlst_last(*head);
		temp->next = new;
		new->prev = temp;
	}
}

void	dlst_clear(t_stack *stack)
{	
	t_dlist	*temp;

	if (stack->head == NULL)
		return ;
	while (stack->head)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
}

void	dlst_add_front(t_dlist **head, t_dlist *new)
{
	if (*head == NULL)
		*head = new;
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
}

t_dlist	*dlst_new(int content)
{
	t_dlist	*list;

	list = malloc(sizeof(*list));
	if (list == NULL)
	{
		ft_putstr_fd("Error: Malloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	list->pos = 0;
	list->content = content;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
