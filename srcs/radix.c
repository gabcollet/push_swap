/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:52:44 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/10 16:23:02 by gcollet          ###   ########.fr       */
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

void	sort_radix(t_stack *a, t_stack *b, int len)
{
	int	x;
	int	y;
	int temp;

	y = 1;
	x = 0;
	while (power(2, y) * 2 < len)
		y++;
	temp = len;
	while (x <= y)
	{
		len = temp;
		while (len-- > 0)
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