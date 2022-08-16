/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:32:06 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/16 20:45:41 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stck **stck)
{
	int	tmp;
	int	size;

	size = (*stck)[0].size;
	tmp = (*stck)[size - 1].value;
	(*stck)[size - 1].value = (*stck)[size - 2].value;
	(*stck)[size - 2].value = tmp;
}

void	ft_push(char c, t_stck **stck_a, t_stck **stck_b)
{
	int	size_a;
	int	size_b;

	size_a = (*stck_a)[0].size;
	size_b = (*stck_b)[0].size;

	if (c == 'b')
	{
		if (size_a == 0)
			return ;
		(*stck_b)[size_b].value = (*stck_a)[size_a - 1].value;
		(*stck_b)[0].size++;
		(*stck_a)[0].size--;
	}
	else if (c == 'a')
	{
		if (size_b == 0)
			return ;
		(*stck_a)[size_a].value = (*stck_b)[size_b - 1].value;
		(*stck_a)[0].size++;
		(*stck_b)[0].size--;
	}
}

void	ft_rotate(t_stck **stck)
{
	int	tmp;
	int	size;
	int	i;

	size = (*stck)[0].size;
	i = size;
	tmp = (*stck)[size - 1].value;
	while (--i >= 0)
	{
		if (i == 0)
			(*stck)[i].value = tmp;
		else
			(*stck)[i].value = (*stck)[i - 1].value;
	}
}

void	ft_rev_rotate(t_stck **stck)
{
	int	tmp;
	int	size;
	int	i;

	size = (*stck)[0].size;
	i = -1;
	tmp = (*stck)[0].value;
	while (++i < size)
	{
		if (i == size - 1)
			(*stck)[i].value = tmp;
		else
			(*stck)[i].value = (*stck)[i + 1].value;
	}
}
