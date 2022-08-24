/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/24 11:02:48 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_manage_extremes(int key_a, t_stck **stck_b, int size_b,
		int **instructions)
{
	t_stck	min;
	t_stck	max;
	int		i;

	ft_get_limits(&min, &max, stck_b);
	if (key_a > max.key)
	{
		i = 0;
		while ((*stck_b)[size_b - i - 1].key != max.key)
			i++;
		while ((*stck_b)[size_b - 1].key != max.key)
			ft_choose_rotation(i, 'b', stck_b, instructions);
		return (1);
	}
	if (key_a < min.key)
	{
		while ((*stck_b)[size_b - 1].key != min.key)
			ft_rotate('b', stck_b, instructions);
		ft_rotate('b', stck_b, instructions);
		return (1);
	}
	return (0);
}

void	ft_prepare_and_push(t_stck **stck_a, t_stck **stck_b,
			int **instructions, int *j)
{
	int	key_a;
	int	size_a;
	int	size_b;
	int	i;

	size_a = (*stck_a)[0].size;
	size_b = (*stck_b)[0].size;
	key_a = (*stck_a)[size_a - 1].key;
	if (size_b < 2
		|| ft_manage_extremes(key_a, stck_b, size_b, instructions) == 1)
	{
		ft_push('b', stck_a, stck_b, instructions);
		(*j)++;
		return ;
	}
	i = 0;
	while (!((*stck_b)[size_b - i - 1].key > key_a
		&& (*stck_b)[size_b - i - 2].key < key_a))
		i++;
	while (!((*stck_b)[0].key > key_a && (*stck_b)[size_b - 1].key < key_a))
		ft_choose_rotation(i, 'b', stck_b, instructions);
	ft_push('b', stck_a, stck_b, instructions);
	(*j)++;
}

void	ft_shift_stack(t_stck **stck_b, int **instructions)
{
	t_stck	min;
	t_stck	max;
	int		i;
	int		size_b;

	size_b = (*stck_b)[0].size;
	ft_get_limits(&min, &max, stck_b);
	i = 0;
	while ((*stck_b)[size_b - i - 1].value != min.value)
		i++;
	while ((*stck_b)[0].value != min.value)
		ft_choose_rotation(i, 'b', stck_b, instructions);
}

void	ft_loop_buckets(t_stck **stck_a, t_stck **stck_b, int size_a,
			int **instructions)
{
	t_buckets	buckets;

	buckets.count = 0.015 * size_a + 3.5;
	buckets.num_per_bucket = size_a / buckets.count;
	ft_allocate_instructions(size_a, buckets.count, buckets.num_per_bucket,
		instructions);
	buckets.key = 0;
	buckets.pass = -1;
	buckets.total_size = size_a;
	while (++buckets.pass < 2 * buckets.count + 1)
	{
		if (buckets.pass == (buckets.count + 1) / 2)
			buckets.num_per_bucket /= 2;
		while (buckets.key < buckets.num_per_bucket * (buckets.pass + 1)
			&& (*stck_a)[0].size > 1)
		{
			size_a = (*stck_a)[0].size;
			if ((*stck_a)[size_a - 1].key
						< buckets.num_per_bucket * (buckets.pass + 1)
						&& (*stck_a)[size_a - 1].key != buckets.total_size - 1)
				ft_prepare_and_push(stck_a, stck_b, instructions, &buckets.key);
			else
				ft_rotate('a', stck_a, instructions);
		}
	}
}

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	size_a;
	int	*instructions;

	size_a = (*stck_a)[0].size;
	ft_loop_buckets(stck_a, stck_b, size_a, &instructions);
	ft_shift_stack(stck_b, &instructions);
	while ((*stck_b)[0].size > 0)
		ft_push('a', stck_a, stck_b, &instructions);
	ft_optimize_and_print_instructions(&instructions);
	free(instructions);
	if (ft_is_ordered(stck_a))
		printf("SUCCESS!\n");
	else
		printf("KO\n");
}
