/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:08:07 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/13 10:08:18 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* void	selectionsort_b(t_stacks *s, int len)
{
	int	small;
	int	big;

	small = smallest_num(s->stack_b);
	while (dlst_len(s->stack_b->head) > 3)
	{
		big = biggest_num(s->stack_b);
		if (is_in_order(s->stack_b->head, -1) != dlst_len(s->stack_b->head))
		{
			while (s->stack_b->head->pos != big)
				direction(s->stack_b, len, big, 2);
		}
		push(s->stack_b, s->stack_a, "pa");
	}
	if (s->stack_b->head->pos == small)
		rotate(s->stack_b, "rb");
	else if (s->stack_b->head->next->pos == small)
		reverse_rotate(s->stack_b, "rrb");
	if (is_in_order(s->stack_b->tail, -1) != 3)
		swap(s->stack_b, "sb");
	while (s->stack_b->head != NULL)
		push(s->stack_b, s->stack_a, "pa");
} */