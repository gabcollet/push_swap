/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:44:36 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/20 15:35:29 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_isnum(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (ft_isdigit(str[i++]) == 0)
		{
			ft_putstr_fd("Error: \"", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("\" is not a number.\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_duplicate(char **argv)
{
	int i;
	int y;

	i = 1;
	while (argv[i])
	{
		y = i + 1;
		while (argv[y])
		{
			if (ft_strcmp(argv[i], argv[y]) == 0)
			{
				ft_putstr_fd("Error: \"", 2);
				ft_putstr_fd(argv[y], 2);
				ft_putstr_fd("\" is a duplicate\n", 2);
				exit(EXIT_FAILURE);
			}
			y++;
		}
		i++;
	}
}

t_stacks	*initialise_stacks()
{
	t_stacks *temp;
	t_stack *stackA;
	t_stack *stackB;

	temp = malloc(sizeof(*temp));
	temp->stackA = malloc(sizeof(*stackA));
	temp->stackB = malloc(sizeof(*stackB));
	temp->stackB->head = NULL;
	temp->stackB->tail = NULL;
	if (temp->stackA == NULL || temp->stackB == NULL)
	{
		ft_putstr_fd("Error: Malloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	return (temp);
}

void	clear_stacks(t_stacks *stacks)
{
	dlst_clear(stacks->stackA);
	dlst_clear(stacks->stackB);
	free(stacks->stackA);
	free(stacks->stackB);
	free(stacks);
}
