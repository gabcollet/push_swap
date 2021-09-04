/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:42:12 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/04 19:50:12 by gcollet          ###   ########.fr       */
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

int	find_median(t_dlist *lst)
{
	int median;
	int	len;
	
	median = 0;
	len = 0;
	while (lst)
	{
		median += lst->pos; 
		len++;
		lst = lst->next;
	}
	median /= len;
	/* if ((median * 2) /2 != median)
		median -= 1; */
	return (median);
}

int	find_pivot(t_dlist *lst)
{
	int	len;
	int	i;

	i = 1;
	len = dlst_len(lst);
	len = assign_pos(len, i, lst);
	/* while (lst->pos != len)
		lst = lst->next; */
	return (len);
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
	while (lst->next)
	{
		if (lst->content < lst->next->content)
			lst = lst->next;
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			pivot;
	// char str[10];
	
	moves = 0; //global value
	stacks = initialise_stacks();
	if (argc > 1)
	{
		create_dlist(stacks->stack_a, argv);
		pivot = find_pivot(stacks->stack_a->head);
		move_a_to_b(stacks, pivot);
		// dlst_print(stacks);//fonction illégal :
		// scanf("%s", str);
		while (is_sorted(stacks->stack_a->head) != 0)
		{	
			while (stacks->stack_a->head != NULL)
			{
				pivot = find_median(stacks->stack_a->head);
				move_a_to_b(stacks, pivot);
				// dlst_print(stacks);//fonction illégal :
				// scanf("%s", str);
			}
			while (stacks->stack_b->head != NULL)
			{
				pivot = find_median(stacks->stack_b->head);
				move_b_to_a(stacks, pivot);
				// dlst_print(stacks);//fonction illégal :
				// scanf("%s", str);
			}
		}
		clear_stacks(stacks);
		printf("moves : %d\n", moves);
	}
	return (0);
}
