/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:31:02 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/10 15:44:42 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	skip_order(t_stack *s, int order, int i)
{
	int	len;

	len = dlst_len(s->head) - order;
	if (len < 0)
		len = -len;
	if (order >= len)
	{
		while (len--)
		{
			if (i == 0)
				reverse_rotate(s, "rra");
			else
				reverse_rotate(s, "rrb");
		}
	}
	else
	{
		while (order--)
		{
			if (i == 0)
				rotate(s, "ra");
			else
				rotate(s, "rb");
		}
	}
}

void	swap_both(t_stacks *s)
{
	if (s->stack_b->head && s->stack_b->head->next
		&& s->stack_a->head->pos > s->stack_a->head->next->pos
		&& s->stack_b->head->pos < s->stack_b->head->next->pos)
	{
		swap(s->stack_a, NULL);
		swap(s->stack_b, "ss");
	}
}

void	quicksort(t_stacks *stacks, int len)
{
	int	order;
	int	sorted;
	// char str[10];

	sorted = 1;
	while (is_sorted(stacks->stack_a->head) != true)
	{	
		order = -1;
		while (order < len && stacks->stack_a->head != NULL)
		{
			move_a_to_b(stacks, len, order);
			len = dlst_len(stacks->stack_a->head);
			order = is_in_order(stacks->stack_a->tail, 1);
			// dlst_print(stacks);//fonction illégal :
			// scanf("%s", str);
		}
		if (stacks->stack_b->head != NULL)
		{
			move_b_to_a(stacks, len, order);
			len = dlst_len(stacks->stack_b->head);
			order = is_in_order(stacks->stack_b->tail, -1);
			if (len == order)
			{
				while (stacks->stack_b->head)
					push(stacks->stack_b, stacks->stack_a, "pa");
			}
			// dlst_print(stacks);//fonction illégal :
			// scanf("%s", str);
			if (stacks->stack_b->head && dlst_len(stacks->stack_b->head) < 20)
				selectionsort_b(stacks, len);
		}
	}
}

void	move_a_to_b(t_stacks *s, int len, int order)
{
	int	pivot;

	pivot = find_median(s->stack_a->head);
	len = dlst_len(s->stack_a->head);
	order = is_in_order(s->stack_a->tail, 1);
	if (order != 1)
		len = len - order;
	while (len--)
	{
		if (s->stack_a->head->pos >= pivot
			&& s->stack_a->head->next->pos >= pivot)
			rotate(s->stack_a, "ra");
		else
		{
			swap_both(s);
			if (s->stack_a->head->pos > s->stack_a->head->next->pos)
				swap(s->stack_a, "sa");
			push(s->stack_a, s->stack_b, "pb");
		}
	}
	skip_order(s->stack_a, order, 0);
}

void	move_b_to_a(t_stacks *s, int len, int order)
{
	int	pivot;

	pivot = find_median(s->stack_b->head);
	len = dlst_len(s->stack_b->head);
	order = is_in_order(s->stack_b->tail, -1);
	if (order != 1)
		len = len - order;
	while (len--)
	{
		if (s->stack_b->head->pos <= pivot)
		{
			if (dlst_len(s->stack_b->head) == 1)
				push(s->stack_b, s->stack_a, "pa");
			else
				rotate(s->stack_b, "rb");
		}
		else
		{
			swap_both(s);
			if (s->stack_b->head->pos < s->stack_b->head->next->pos)
				swap(s->stack_b, "sb");
			push(s->stack_b, s->stack_a, "pa");
		}
	}
	skip_order(s->stack_b, order, 1);
}

int	find_median(t_dlist *lst)
{
	int	median;
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
