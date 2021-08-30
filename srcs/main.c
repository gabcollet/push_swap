/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:42:12 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/30 15:02:04 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void create_dlist(t_stack *stackA, char **argv)
{
	t_dlist *temp;
	char	**args;
	int i;
	int y;

	i = 1;
	y = 0;
	check_duplicate(argv, 1);
	while(argv[i])
	{
		args = ft_split(argv[i++], ' ');
		check_duplicate(args, 0);
		while (args[y])
		{
			ft_isnum(args[y]);
			temp = dlst_new(ft_atoi(args[y++]));
			dlst_add_back(&stackA->head, temp);
		}
		stackA->tail = dlst_last(stackA->head);
		while (y > 0 && args[--y])
			free(args[y]);
		free(args);
		y = 0;
	}
}

int main(int argc, char **argv)
{
	t_stacks *stacks;

	stacks = initialise_stacks();
	if (argc > 1)
		create_dlist(stacks->stackA, argv);
	else
		ft_putstr_fd("Error : Missing argument", 2);

	//fonction illégal :
	dlst_print(stacks);
	//-----------------
	clear_stacks(stacks);

	return (0);
}
