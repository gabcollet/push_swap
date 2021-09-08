/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:31:02 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/08 18:41:34 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_power(int n, int ex)
{
    int    pow;

    pow = 1;
    while (ex-- > 0)
        pow = n * pow;
    return (pow);
}

void    ft_sort_radix(t_stack *a, t_stack *b)
{
    double     x;
    int        i;

    x = 0;
    while (x <= 8) //max_x c'est le plus grand exposant nécessaire
    {
        i = 500; //le nombre d'élément en ce moment dans ta stack a
        while (i-- > 0)
        {
            //ft_power c'est 2 exposant x et i c'est les indexes dans mon stack
            // le ^ c'est un bitwise operator, je te l'expliquerai plus tard si tu fais ça
            if ((a->head->pos ^ ft_power(2, x)) > a->head->pos)
                push(a, b, "pb");
            else
                rotate(a, "ra");
        }
        while (b->head != NULL)
            push(b, a, "pa");
        x++;
    }
}

/* int	check_direction(t_dlist *lst, int pivot)
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
} */

void	move_a_to_b(t_stacks *s)
{
	int	len;
	int	pivot;
	int	order;

	pivot = find_median(s->stack_a->head);
	len = dlst_len(s->stack_a->head);
	order = is_in_order(s->stack_a->tail, 1);
	if (order != 1)
		len = len - order;
	while (len-- && s->stack_a->head->next)
	{
		if (s->stack_a->head->pos >= pivot
			&& s->stack_a->head->next->pos >= pivot)
			rotate(s->stack_a, "ra");
		else
		{
			if (s->stack_b->head && s->stack_b->head->next
				&& s->stack_a->head->pos > s->stack_a->head->next->pos
				&& s->stack_b->head->pos < s->stack_b->head->next->pos)
			{
				swap(s->stack_a, NULL);
				swap(s->stack_b, "ss");
			}
			else if (s->stack_a->head->pos > s->stack_a->head->next->pos)
				swap(s->stack_a, "sa");
			push(s->stack_a, s->stack_b, "pb");
		}
	}
	len = dlst_len(s->stack_a->head) - order;
	if (order >= len)
	{
		while (len--)
			reverse_rotate(s->stack_a, "rra");
	}
	else
	{
		while (order--)
			rotate(s->stack_a, "ra");
	}
}

void	move_b_to_a(t_stacks *s)
{
	int	len;
	int	pivot;
	int	order;

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
			if (s->stack_a->head && s->stack_a->head->next
				&& s->stack_a->head->pos > s->stack_a->head->next->pos
				&& s->stack_b->head->pos < s->stack_b->head->next->pos)
			{
				swap(s->stack_a, NULL);
				swap(s->stack_b, "ss");
			}
			else if (s->stack_b->head->pos < s->stack_b->head->next->pos)
				swap(s->stack_b, "sb");
			push(s->stack_b, s->stack_a, "pa");
		}
	}
	len = dlst_len(s->stack_b->head) - order;
	if (len < 0)
		len = -len;
	if (order >= len)
	{
		while (len--)
			reverse_rotate(s->stack_b, "rrb");
	}
	else
	{
		while (order--)
			rotate(s->stack_b, "rb");
	}
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
