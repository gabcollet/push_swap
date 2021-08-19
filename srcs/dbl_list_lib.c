/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_list_lib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:24:11 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/19 15:48:10 by gcollet          ###   ########.fr       */
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

void	dlst_add_back(t_dlist **head, t_dlist *new)
{
	t_dlist *temp;

	if (*head == NULL)
		*head = new;
	else
	{
		temp = dlst_last(*head);
		temp->next = new;
		new->prev = temp;
	}
}

void	dlst_clear(t_dlist *head)
{	
	t_dlist	*temp;

	if (head == NULL)
		return ;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
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
	list->content = content;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
