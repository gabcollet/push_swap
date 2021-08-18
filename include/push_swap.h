/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:57:49 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/18 19:10:02 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
#include <stdio.h> //fonction interdit

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist	*dlst_last(t_dlist *lst);
t_dlist	*dlst_new(int content);
void	dlst_add_front(t_dlist **head, t_dlist *new);
void	dlst_add_back(t_dlist **head, t_dlist *new);
void	dlst_print(t_dlist **head);
void	dlst_reverseprint(t_dlist **head);
void	dlst_clear(t_dlist **head);

#endif
