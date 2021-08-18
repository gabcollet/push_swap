/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:42:12 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/18 17:48:11 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	int i;
	t_dlist *head;
	t_dlist *temp;
	
	i = 2;
	if (argc > 1)
	{
		head = dlst_new(ft_atoi(argv[1]));
		while(argv[i])
		{
			temp = dlst_new(ft_atoi(argv[i]));
			dlst_add_back(&head, temp);
			i++;
		}
		dlst_print(&head);
	/* 	dlst_reverseprint(&head); */
	}
	else
		ft_putstr_fd("Error : Missing argument", 2);
	return (0);
}
