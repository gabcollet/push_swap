/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:42:12 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/13 10:16:43 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	assign_pos(int len, int i, t_dlist *lst)
{
	t_dlist	*temp;
	t_dlist	*small;
	t_dlist	*big;

	while (len >= i)
	{
		temp = lst;
		while (temp->pos != 0)
			temp = temp->next;
		small = temp;
		big = temp;
		while (temp)
		{
			if (small->content > temp->content && temp->pos == 0)
				small = temp;
			if (big->content < temp->content && temp->pos == 0)
				big = temp;
			temp = temp->next;
		}
		small->pos = i++;
		big->pos = len--;
	}
	return (++len);
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
			ft_isint(args[y]);
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

int	is_sorted(t_dlist *lst)
{
	if (lst->pos != 1)
		return (false);
	while (lst->next)
	{
		if (lst->content < lst->next->content)
			lst = lst->next;
		else
			return (false);
	}
	return (true);
}

int	is_in_order(t_dlist *lst, int i)
{
	int	order;

	order = 0;
	if (lst && lst->prev)
	{
		if (i == -1)
		{
			if (lst->pos != 1)
				return (order);
		}
		order = 1;
		while (lst->prev && lst->pos == lst->prev->pos + i)
		{
			order++;
			lst = lst->prev;
		}
	}
	return (order);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			len;

	stacks = initialise_stacks();
	if (argc > 1)
	{
		create_dlist(stacks->stack_a, argv);
		len = dlst_len(stacks->stack_a->head);
		assign_pos(len, 1, stacks->stack_a->head);
		if (len < 30)
			selectionsort(stacks, len);
		else
			sort_radix(stacks->stack_a, stacks->stack_b, len);
		clear_stacks(stacks);
	}
	return (0);
}
