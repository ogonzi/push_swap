/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:16:51 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/19 11:57:19 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

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
	int chunk_size;
	int	pass;
	int	size_a;
	int	i;
	int	j;

	pass = 0;
	chunk_size = 5;
	j = 0;
	while (pass < 2)
	{
		size_a = (*stck_a)[0].size;
		while ((*stck_b)[0].size != chunk_size * (pass + 1))
			ft_push('b', stck_a, stck_b);
		i = 0;
		while (i < chunk_size * 2 * (pass + 1))
		{
			size_a = (*stck_a)[0].size;
			if ((*stck_a)[size_a - 1].value > (*stck_b)[0].value)
			{
				ft_rev_rotate('b', stck_b);
				ft_push('a', stck_a, stck_b);
			}
			ft_rotate('a', stck_a);
			i++;
		}
		//while ((*stck_a)[size - 1].value > (*stck_a)[size - 2].value)
		//	ft_rotate('a', stck_a);
		/*
		while ((*stck_b)[0].size != 0)
		{
			ft_rev_rotate('b', stck_b);
			ft_push('a', stck_a, stck_b);
			ft_rotate('a', stck_a);
		}
		*/
		j = j + chunk_size * (pass + 1);
		if (j == size)
		{
			pass++;
			j = 0;
		}
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
