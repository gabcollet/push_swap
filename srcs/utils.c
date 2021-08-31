/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:44:36 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/31 19:36:40 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_isnum(char *str)
{
	int	i;
	long temp;

	i = 0;
	temp = ft_atol(str);
	if (temp < INT_MIN || temp > INT_MAX)
		error();
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i++]) == 0)
			error();
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
	t_stack		*stackA;
	t_stack		*stackB;

	temp = malloc(sizeof(*temp));
	temp->stackA = malloc(sizeof(*stackA));
	temp->stackB = malloc(sizeof(*stackB));
	temp->stackB->head = NULL;
	temp->stackB->tail = NULL;
	if (temp->stackA == NULL || temp->stackB == NULL)
		error();
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
