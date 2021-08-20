/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_list_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:13:09 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/20 18:21:43 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	dlst_print(t_stacks *stacks)
{
	t_dlist	*tempA;
	t_dlist	*tempB;
	char str[30];
	
	tempA = stacks->stackA->head;
	tempB = stacks->stackB->head;
	while (ft_strcmp(str, "quit"))
	{
		printf("\n");
		while(tempA)
		{
			printf("%d", tempA->content);
			if (tempB == NULL)
				printf("\n");
			else
			{
				if (tempB)
				{
					printf(" %d\n", tempB->content);
					tempB = tempB->next;
				}
			}
			tempA = tempA->next;
		}
		printf("- -\n");
		printf("A B\n ");
		printf("Enter command sa\\ra\\quit : ");
		scanf("%s", str);
		if (ft_strcmp(str, "sa") == 0)
			stacks->stackA->head = swap_a(stacks->stackA->head);
		if (ft_strcmp(str, "ra") == 0)
			stacks->stackA = rotate_a(stacks->stackA);
		if (ft_strcmp(str, "rra") == 0)
			stacks->stackA = reverse_rotate_a(stacks->stackA);
		if (ft_strcmp(str, "pb") == 0)
			stacks = push_b(stacks);
		tempA = stacks->stackA->head;
		tempB = stacks->stackB->head;
	}
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
