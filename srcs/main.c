/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:42:12 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/02 09:59:14 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_pivot(t_dlist	*lst)
{
	int		len;
	int		pivot;
	t_dlist	*smaller;
	t_dlist *temp;
	t_stack	*stack_c;
	
	len = dlst_count(lst);
	pivot = 0;
	temp = lst;
	smaller = temp;
	stack_c = malloc(sizeof(*stack_c));
	if (stack_c == NULL)
		error();
	while (pivot <= (len / 2))
	{
		while(temp->next) //trouve le plus petit node
		{
			printf("%d\n", smaller->content);
			if (smaller->content > temp->content /* && smaller->content > stack_c->head->content */)
			{
				
				smaller = temp;
			}
			temp = temp->next;
		}
		smaller = dlst_new(temp->content);
		dlst_add_back(&stack_c->head, smaller);
		temp = lst;
		pivot = dlst_count(stack_c->head);
		printf("%d\n", pivot);
	}
	while (pivot--)
		stack_c->head = stack_c->head->next;
	pivot = stack_c->head->content;
	dlst_clear(stack_c);
	return (pivot);
}

void	create_dlist(t_stack *stack_a, char **argv)
{
	t_dlist	*temp;
	char	**args;
	int		i;
	int		y;

	i = 1;
	y = 0;
	check_duplicate(argv, 1);
	while (argv[i])
	{
		args = ft_split(argv[i++], ' ');
		check_duplicate(args, 0);
		while (args[y])
		{
			ft_isnum(args[y]);
			temp = dlst_new(ft_atoi(args[y++]));
			dlst_add_back(&stack_a->head, temp);
		}
		stack_a->tail = dlst_last(stack_a->head);
		while (y > 0 && args[--y])
			free(args[y]);
		free(args);
		y = 0;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int	pivot;

	stacks = initialise_stacks();
	if (argc > 1)
	{
		create_dlist(stacks->stack_a, argv);
		pivot = find_pivot(stacks->stack_a->head);
		printf("%d\n", pivot);
		/* dlst_print(stacks);//fonction illégal : */
		clear_stacks(stacks);
	}
	return (0);
}
