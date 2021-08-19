/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_list_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:13:09 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/19 15:18:15 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	dlst_print(t_dlist *head)
{
	t_dlist	*temp;
	
	temp = head;
	printf("\n");
	while(temp)
	{
		printf("   %d\n", temp->content);
		temp = temp->next;
	}
	printf("--------\n");
	printf(" StackA\n ");
}

void	dlst_reverseprint(t_dlist *head)
{
	t_dlist	*temp;

	temp = head;
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
