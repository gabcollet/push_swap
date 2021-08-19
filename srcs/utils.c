/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:44:36 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/19 15:44:57 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_isnum(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (ft_isdigit(str[i++]) == 0)
		{
			ft_putstr_fd("Error: \"", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("\" is not a number.\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}
