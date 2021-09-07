/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:31:02 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/07 16:17:08 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_moves(char *str) //cette fonction peux allé directement dans les operations
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	moves++; //global value ---- remplacer par un | wc -l
}

int	check_direction(t_dlist *lst, int pivot)
{
	int ra;
	int rra;
	t_dlist *temp;

	ra = 0;
	rra = 0;
	temp = dlst_last(lst);
	while (lst->next && lst->pos != pivot)
	{
		lst = lst->next;
		ra++;	
	}
	while (temp->prev && temp->pos != pivot)
	{
		temp = temp->prev;
		rra++;
	}
	if (ra <= rra)
		return (0); //si ca doit faire ra
	return (1); //si ca doit faire rra
}

void	move_a_to_b(t_stacks *stacks)
{
	int	len;
	int pivot;
	/* int order; */

	pivot = find_median(stacks->stack_a->head);
	len = dlst_len(stacks->stack_a->head);
	/* order = is_in_order(stacks->stack_a->tail, 1);
	len = len - order; */
	//quand c'est rendu à ce qui est trié il devrait rembobinner au lieu de le checker
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
	/* if (order >= dlst_len(stacks->stack_a->head))
	{
		while (order--)
		{
			reverse_rotate(stacks->stack_a);
			write_moves("rra");
		}
	}
	else
	{
		while (order--)
		{
			rotate(stacks->stack_a);
			write_moves("ra");
		}
	} */
	//fonction qui valide si on doit aller en ra ou en rra
	while (stacks->stack_a->head->pos != pivot)
	{
		if (check_direction(stacks->stack_a->head, pivot) == 0)
		{
			rotate(stacks->stack_a);
			write_moves("ra");
		}
		else
		{
			reverse_rotate(stacks->stack_a);
			write_moves("rra");
		}
	}
	push(stacks->stack_a, stacks->stack_b);
	write_moves("pb");
}

void	move_b_to_a(t_stacks *stacks)
{
	int	len;
	int pivot;

	pivot = find_median(stacks->stack_b->head);
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
		if (check_direction(stacks->stack_b->head, pivot) == 0)
		{
			rotate(stacks->stack_b);
			write_moves("rb");
		}
		else
		{
			reverse_rotate(stacks->stack_b);
			write_moves("rrb");
		}
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
