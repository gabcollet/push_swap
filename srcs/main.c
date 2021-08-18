/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:42:12 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/18 19:13:09 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	int i;
	int y;
	t_dlist *head;
	t_dlist *temp;
	char	**args;
	
	i = 1;
	y = 0;
	if (argc > 1)
	{
		while(argv[i])
		{
			args = ft_split(argv[i++], ' ');
			while (args[y])
			{
				temp = dlst_new(ft_atoi(args[y++]));
				dlst_add_back(&head, temp);
			}
			while (y > 0 && args[--y])
				free(args[y]);
			free(args);
			y = 0;
		}
		dlst_print(&head);
		/* dlst_reverseprint(&head); */
	}
	else
		ft_putstr_fd("Error : Missing argument", 2);
	dlst_clear(&head);
	return (0);
}
