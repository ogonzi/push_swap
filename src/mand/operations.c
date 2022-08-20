/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:32:06 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/20 13:45:06 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_swap(char c, t_stck **stck)
{
	t_stck	tmp;
	int		size;

	size = (*stck)[0].size;
	tmp.value = (*stck)[size - 1].value;
	tmp.key = (*stck)[size - 1].key;
	(*stck)[size - 1].value = (*stck)[size - 2].value;
	(*stck)[size - 1].key = (*stck)[size - 2].key;
	(*stck)[size - 2].value = tmp.value;
	(*stck)[size - 2].key = tmp.key;
	ft_printf("s%c\n", c);
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
		(*stck_b)[size_b].key = (*stck_a)[size_a - 1].key;
		(*stck_b)[0].size++;
		(*stck_a)[0].size--;
	}
	else if (c == 'a')
	{
		if (size_b == 0)
			return ;
		(*stck_a)[size_a].value = (*stck_b)[size_b - 1].value;
		(*stck_a)[size_a].key = (*stck_b)[size_b - 1].key;
		(*stck_a)[0].size++;
		(*stck_b)[0].size--;
	}
	ft_printf("p%c\n", c);
}

void	ft_rotate(char c, t_stck **stck)
{
	t_stck	tmp;
	int		size;
	int		i;

	size = (*stck)[0].size;
	i = size;
	tmp.value = (*stck)[size - 1].value;
	tmp.key = (*stck)[size - 1].key;
	while (--i >= 0)
	{
		if (i == 0)
		{
			(*stck)[i].value = tmp.value;
			(*stck)[i].key = tmp.key;
		}
		else
		{
			(*stck)[i].value = (*stck)[i - 1].value;
			(*stck)[i].key = (*stck)[i - 1].key;
		}
	}
	ft_printf("r%c\n", c);
}

void	ft_rev_rotate(char c, t_stck **stck)
{
	t_stck	tmp;
	int		size;
	int		i;

	size = (*stck)[0].size;
	i = -1;
	tmp.value = (*stck)[0].value;
	tmp.key = (*stck)[0].key;
	while (++i < size)
	{
		if (i == size - 1)
		{
			(*stck)[i].value = tmp.value;
			(*stck)[i].key = tmp.key;
		}
		else
		{
			(*stck)[i].value = (*stck)[i + 1].value;
			(*stck)[i].key = (*stck)[i + 1].key;
		}
	}
	ft_printf("rr%c\n", c);
}
