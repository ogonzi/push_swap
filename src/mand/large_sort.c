/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:16:51 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/19 20:01:42 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "libft.h"
#include <stdio.h>

void	ft_split_by_sign(t_stck **stck_a, t_stck **stck_b, int size)
{
	int	i;
	int	current_size;

	i = 0;
	while (i < size)
	{
		current_size = (*stck_a)[0].size;
		if ((*stck_a)[current_size - 1].value < 0)
			ft_push('b', stck_a, stck_b);
		else
			ft_rotate('a', stck_a);
		i++;
	}
}

void	ft_split_stack(t_stck **stck_a, t_stck **stck_b)
{
	int	i;
	int	current_size;
	int	start_size;
	t_stck	max;
	t_stck	min;

	ft_get_max(&max, stck_a);
	ft_get_min(&min, stck_b);
	start_size = (*stck_a)[0].size;
	i = 0;
	while (i < start_size)
	{
		current_size = (*stck_a)[0].size;
		if ((*stck_a)[current_size - 1].value < (max.value / 2))
			ft_push('b', stck_a, stck_b);
		else
			ft_rotate('a', stck_a);
		i++;
	}
	i = 0;
	start_size = (*stck_b)[0].size;
	i = 0;
	while (i < start_size)
	{
		current_size = (*stck_b)[0].size;
		if ((*stck_b)[current_size - 1].value > (min.value / 2))
			ft_push('a', stck_a, stck_b);
		else
			ft_rotate('b', stck_b);
		i++;
	}
}

void	ft_sort_chunks(t_stck **stck_a, t_stck **stck_b, int size)
{
	int	chunks;
	int	i;

	if ((*stck_b)[0].size > 5)
	{
		while ((*stck_b)[0].size != 5)
			ft_push('a', stck_a, stck_b);
	}
	else if ((*stck_b)[0].size < 5)
	{
		while ((*stck_b)[0].size != 5)
			ft_push('b', stck_a, stck_b);
	}
	chunks = size / 5;
	while (chunks != 0)
	{
		ft_sort_five(stck_b, stck_a);
		i = 0;
		while (i < 5)
		{
			ft_push('a', stck_a, stck_b);
			ft_rotate('a', stck_a);
			i++;
		}
		if (chunks == 1)
			break ;
		i = 0;
		while (i < 5)
		{
			ft_push('b', stck_a, stck_b);
			i++;
		}
		chunks--;
	}
}

void	ft_sort_all(t_stck **stck_a, t_stck **stck_b, int size)
{
	int	pass;
	int	size_a;
	int	size_b;
	int	j;
	t_stck	max;

	printf("ft_sort_all\n");
	pass = 0;
	j = 0;
	ft_get_max(&max, stck_a);
	printf("max value = %d\n", max.value);
	while (pass < 1)
	{
		size_a = (*stck_a)[0].size;
		if ((*stck_b)[0].size == 0 && (*stck_a)[size_a - 1].value < (*stck_a)[size_a - 2].value
				&& (*stck_a)[size - 1].value != max.value)
			ft_push('b', stck_a, stck_b);
		size_a = (*stck_a)[0].size;
		size_b = (*stck_b)[0].size;
		while ((*stck_a)[size_a - 1].value > (*stck_b)[size_b - 1].value
				&& (*stck_a)[size - 1].value != max.value)
		{
			ft_push('b', stck_a, stck_b);
			size_a = (*stck_a)[0].size;
			size_b = (*stck_b)[0].size;
		}
		while ((*stck_b)[0].size != 0 && j < size)
		{
			size_a = (*stck_a)[0].size;
			if ((*stck_a)[size_a - 1].value > (*stck_b)[0].value)
			{
				ft_rev_rotate('b', stck_b);
				ft_push('a', stck_a, stck_b);
			}
			ft_rotate('a', stck_a);
			j++;
		}
		if (j == size)
			pass++;
	}
	(void)size;
}

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	size;

	if (ft_is_ordered(stck_a) == 1)
		return ;
	size = (*stck_a)[0].size;
	ft_split_by_sign(stck_a, stck_b, size);	
	ft_split_stack(stck_a, stck_b);
	ft_sort_chunks(stck_a, stck_b, size);
	if (ft_is_ordered(stck_a) == 1)
		return ;
	ft_sort_all(stck_a, stck_b, size);
}
