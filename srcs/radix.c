/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:52:44 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/09 15:05:28 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	power(int n, int ex)
{
	int	pow;

	pow = 1;
	while (ex-- > 0)
		pow = n * pow;
	return (pow);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	double	x;
	int		i;

	x = 0;
	while (x <= 8)
	{
		i = 500;
		while (i-- > 0)
		{
			if ((a->head->pos ^ power(2, x)) > a->head->pos)
				push(a, b, "pb");
			else
				rotate(a, "ra");
		}
		while (b->head != NULL)
			push(b, a, "pa");
		x++;
	}
}