/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:32:06 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/24 12:52:09 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "utils_bonus.h"
#include "ft_printf.h"

void	ft_swap(t_stck **stck)
{
	t_stck	tmp;
	int		size;

	size = (*stck)[0].size;
	if (size < 2)
		return ;
	tmp.value = (*stck)[size - 1].value;
	(*stck)[size - 1].value = (*stck)[size - 2].value;
	(*stck)[size - 2].value = tmp.value;
}

void	ft_push(t_stck **to, t_stck **from)
{
	int	size_to;
	int	size_from;

	size_to = (*to)[0].size;
	size_from = (*from)[0].size;
	if (size_from == 0)
		return ;
	(*to)[size_to].value = (*from)[size_from - 1].value;
	(*to)[0].size++;
	(*from)[0].size--;
}

void	ft_rotate(t_stck **stck)
{
	t_stck	tmp;
	int		size;
	int		i;

	size = (*stck)[0].size;
	i = size;
	tmp.value = (*stck)[size - 1].value;
	while (--i >= 0)
	{
		if (i == 0)
		{
			(*stck)[i].value = tmp.value;
			break ;
		}
		(*stck)[i].value = (*stck)[i - 1].value;
	}
}

void	ft_rev_rotate(t_stck **stck)
{
	t_stck	tmp;
	int		size;
	int		i;

	size = (*stck)[0].size;
	i = -1;
	tmp.value = (*stck)[0].value;
	while (++i < size)
	{
		if (i == size - 1)
		{
			(*stck)[i].value = tmp.value;
			break ;
		}
		(*stck)[i].value = (*stck)[i + 1].value;
	}
}
