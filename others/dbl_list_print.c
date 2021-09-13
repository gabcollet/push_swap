/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_list_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:13:09 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/08 10:34:40 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* char	*take_command(t_stacks *stacks, char *str)
{
	printf("\nEnter command sa\\sb\\ss\\ra\\rb\\rr\\rra\\rrb\\rrr\\pb\\pa\\quit : ");
	scanf("%s", str);
	if (ft_strcmp(str, "sa") == 0)
		swap(stacks->stack_a);
	if (ft_strcmp(str, "sb") == 0)
		swap(stacks->stack_b);
	if (ft_strcmp(str, "ss") == 0)
	{
		swap(stacks->stack_a);
		swap(stacks->stack_b);
	}
	if (ft_strcmp(str, "ra") == 0)
		rotate(stacks->stack_a);
	if (ft_strcmp(str, "rb") == 0)
		rotate(stacks->stack_b);
	if (ft_strcmp(str, "rr") == 0)
	{
		rotate(stacks->stack_a);
		rotate(stacks->stack_b);
	}
	if (ft_strcmp(str, "rra") == 0)
		reverse_rotate(stacks->stack_a);
	if (ft_strcmp(str, "rrb") == 0)
		reverse_rotate(stacks->stack_b);
	if (ft_strcmp(str, "rrr") == 0)
	{
		reverse_rotate(stacks->stack_a);
		reverse_rotate(stacks->stack_b);
	}
	if (ft_strcmp(str, "pb") == 0)
		push(stacks->stack_a, stacks->stack_b);
	if (ft_strcmp(str, "pa") == 0)
		push(stacks->stack_b, stacks->stack_a);
	return (str);
} */

void	dlst_print(t_stacks *stacks)
{
	t_dlist	*temp_a;
	t_dlist	*temp_b;
/* 	char str[30]; */
	
	temp_a = stacks->stack_a->head;
	temp_b = stacks->stack_b->head;
/* 	while (ft_strcmp(str, "quit"))
	{ */
		printf("\n");
		while(temp_a)
		{
			printf("%5d", temp_a->content);
			if (temp_b == NULL)
				printf("\n");
			else
			{
				if (temp_b)
				{
					printf(" %5d\n", temp_b->content);
					temp_b = temp_b->next;
				}
			}
			temp_a = temp_a->next;
		}
		while(temp_b)
		{
			printf("     ");
			printf(" %5d\n", temp_b->content);
			temp_b = temp_b->next;
		}
		printf("    -     -\n");
		printf("    A     B\n");

		// if (stacks->stack_a->head)
		// 	printf("\nHead A : %d\n", stacks->stack_a->head->content);
		// else
		// 	printf("\nHead A : NULL\n");
		// if (stacks->stack_a->tail)
		// 	printf("Tail A : %d\n", stacks->stack_a->tail->content);
		// else
		// 	printf("Tail A : NULL\n");
		// if (stacks->stack_b->head)
		// 	printf("\nHead B : %d\n", stacks->stack_b->head->content);
		// else
		// 	printf("\nHead B : NULL\n");
		// if (stacks->stack_b->tail)
		// 	printf("Tail B : %d\n", stacks->stack_b->tail->content);
		// else
		// 	printf("Tail B : NULL\n");
		/* take_command(stacks, str); */
		temp_a = stacks->stack_a->head;
		temp_b = stacks->stack_b->head;
	/* } */
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
