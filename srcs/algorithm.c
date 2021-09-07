/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:31:02 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/07 11:45:13 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_moves(char *str) //cette fonction peux allé directement dans les operations
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	moves++; //argument global
}

void	move_a_to_b(t_stacks *stacks, int pivot)
{
	int	len;
	// int	order;

	// order = 0;
	// order = is_in_order(stacks->stack_a->tail, order);
	len = dlst_len(stacks->stack_a->head);
	// len -= order;
	while (len-- && stacks->stack_a->head->next)
	{
		if (stacks->stack_a->head->pos >= pivot && stacks->stack_a->head->next->pos >= pivot)
		{
			rotate(stacks->stack_a);
			write_moves("ra");
		}
		else
		{
			if (stacks->stack_a->head->pos > stacks->stack_a->head->next->pos)
			{
				swap(stacks->stack_a);
				write_moves("sa");
			}
			push(stacks->stack_a, stacks->stack_b);
			write_moves("pb");
		}
	}
	while (stacks->stack_a->head->pos != pivot)
	{
		rotate(stacks->stack_a);
		write_moves("ra");
	}
	push(stacks->stack_a, stacks->stack_b);
	write_moves("pb");
}

void	move_b_to_a(t_stacks *stacks, int pivot)
{
	int	len;

	len = dlst_len(stacks->stack_b->head);
	while (len--)
	{
		if (stacks->stack_b->head->pos <= pivot)
		{
			rotate(stacks->stack_b);
			write_moves("rb");
		}
		else
		{
			if (stacks->stack_b->head->pos < stacks->stack_b->head->next->pos)
			{
				swap(stacks->stack_b);
				write_moves("sb");
			}
			push(stacks->stack_b, stacks->stack_a);
			write_moves("pa");
		}
	}
	while (stacks->stack_b->head->pos != pivot)
	{
		rotate(stacks->stack_b);
		write_moves("rb");
	}
	push(stacks->stack_b, stacks->stack_a);
	write_moves("pa");
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
	return (median);
}
