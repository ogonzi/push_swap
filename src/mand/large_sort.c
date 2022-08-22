/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/22 11:02:12 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdio.h>

int	ft_manage_extremes(int key_a, t_stck **stck_b, int size_b)
{
	t_stck	min;
	t_stck	max;
	int		i;

	ft_get_max(&max, stck_b);
	ft_get_min(&min, stck_b);
	if (key_a > max.key)
	{
		i = 0;
		while ((*stck_b)[size_b - i - 1].key != max.key)
			i++;
		while ((*stck_b)[size_b - 1].key != max.key)
			ft_choose_rotation(i, size_b, 'b', stck_b);
		return (1);
	}
	if (key_a < min.key)
	{
		while ((*stck_b)[size_b - 1].key != min.key)
			ft_rotate('b', stck_b);
		ft_rotate('b', stck_b);
		return (1);
	}
	return (0);
}

void	ft_prepare_bucket(int key_a, t_stck **stck_b)
{
	int		size_b;
	int		i;

	size_b = (*stck_b)[0].size;
	if (size_b < 2)
		return ;
	if (ft_manage_extremes(key_a, stck_b, size_b) == 1)
		return ;
	i = 0;
	while (!((*stck_b)[size_b - i - 1].key > key_a
		&& (*stck_b)[size_b - i - 2].key < key_a))
		i++;
	while (!((*stck_b)[0].key > key_a && (*stck_b)[size_b - 1].key < key_a))
		ft_choose_rotation(i, size_b, 'b', stck_b);
}

void	ft_reset_bucket(t_stck **stck_b)
{
	t_stck	min;
	int		i;
	int		size_b;

	size_b = (*stck_b)[0].size;
	ft_get_min(&min, stck_b);
	i = 0;
	while ((*stck_b)[size_b - i - 1].value != min.value)
		i++;
	while ((*stck_b)[0].value != min.value)
		ft_choose_rotation(i, size_b, 'b', stck_b);
}

void	ft_loop_buckets(t_stck **stck_a, t_stck **stck_b, int size_a)
{
	int	num_buckets;
	int	num_per_bucket;
	int	j;
	int	pass;

	num_buckets = 0.015 * (*stck_a)[0].size + 3.5;
	num_per_bucket = (*stck_a)[0].size / num_buckets;
	j = 0;
	pass = -1;
	while (++pass < num_buckets + 1)
	{
		while (j < num_per_bucket * (pass + 1) && (*stck_a)[0].size != 0)
		{
			size_a = (*stck_a)[0].size;
			if ((*stck_a)[size_a - 1].key < num_per_bucket * (pass + 1))
			{
				ft_prepare_bucket((*stck_a)[size_a - 1].key, stck_b);
				ft_push('b', stck_a, stck_b);
				j++;
			}
			else
				ft_rotate('a', stck_a);
		}
		ft_reset_bucket(stck_b);
	}
}

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	size_a;

	size_a = (*stck_a)[0].size;
	ft_loop_buckets(stck_a, stck_b, size_a);
	while ((*stck_b)[0].size > 0)
		ft_push('a', stck_a, stck_b);
	if (ft_is_ordered(stck_a))
		printf("SUCCESS!\n");
	else
		printf("KO\n");
}
