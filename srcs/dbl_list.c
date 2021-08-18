/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:24:11 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/18 19:10:56 by gcollet          ###   ########.fr       */
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

void	dlst_print(t_dlist **head)
{
	t_dlist	*temp;
	
	temp = *head;
	while(temp)
	{
		printf("  %d\n", temp->content);
		temp = temp->next;
	}
	printf("-------\n");
	printf(" Stack ");
}

void	dlst_reverseprint(t_dlist **head)
{
	t_dlist	*temp;

	temp = *head;
	if (temp == NULL)
		return;
	temp = dlst_last(temp);
	
	printf("Reverse: ");
	while(temp)
	{
		printf("%d ",temp->content);
		temp = temp->prev;
	}
	printf("\n");
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

void	dlst_clear(t_dlist **head)
{	
	t_dlist	*temp;

	if (*head == NULL)
		return ;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
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
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
