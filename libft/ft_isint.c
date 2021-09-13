/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:53:33 by gcollet           #+#    #+#             */
/*   Updated: 2021/09/13 10:53:52 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_isint(char *str)
{
	int		i;
	long	temp;

	i = 0;
	temp = ft_atol(str);
	if (temp < INT_MIN || temp > INT_MAX)
		error();
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i++]) == 0)
			error();
	}
}
