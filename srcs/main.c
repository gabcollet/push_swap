/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:42:12 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/19 15:44:54 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_dlist *create_dlist(t_dlist *head, char **argv)
{
	t_dlist *temp;
	char	**args;
	int i;
	int y;
	
	i = 1;
	y = 0;
	while(argv[i])
	{
		args = ft_split(argv[i++], ' ');
		while (args[y])
		{
			ft_isnum(args[y]);
			temp = dlst_new(ft_atoi(args[y++]));
			dlst_add_back(&head, temp);
		}
		while (y > 0 && args[--y])
			free(args[y]);
		free(args);
		y = 0;
	}
	return (head);
}

int main(int argc, char **argv)
{
	t_stack stackA;
	/* t_dlist *stackB; */
	
	if (argc > 1)
	{
		stackA.head = create_dlist(stackA.head, argv);
		stackA.tail = dlst_last(stackA.head);
	}
	else
		ft_putstr_fd("Error : Missing argument", 2);

	//fonction illégal :	
	dlst_print(stackA.head);
	printf("\nHead : %d\n", stackA.head->content);
	printf("Tail : %d\n\n", stackA.tail->content);
	//-----------------
	dlst_clear(stackA.head);
	return (0);
}
