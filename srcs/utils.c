/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:44:36 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/13 11:24:07 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
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

void	check_duplicate(char **argv, int i)
{
	int	y;

	while (argv[i])
	{
		y = i + 1;
		while (argv[y])
		{
			if (ft_strcmp(argv[i], argv[y]) == 0)
				error();
			y++;
		}
		i++;
	}
}

t_stacks	*initialise_stacks(void)
{
	t_stacks	*temp;
	t_stack		*stack_a;
	t_stack		*stack_b;

	temp = malloc(sizeof(*temp));
	temp->stack_a = malloc(sizeof(*stack_a));
	temp->stack_b = malloc(sizeof(*stack_b));
	temp->stack_b->head = NULL;
	temp->stack_b->tail = NULL;
	if (temp->stack_a == NULL || temp->stack_b == NULL)
		error();
	return (temp);
}

void	clear_stacks(t_stacks *stacks)
{
	dlst_clear(stacks->stack_a);
	dlst_clear(stacks->stack_b);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}
