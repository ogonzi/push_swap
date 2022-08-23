/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/23 20:27:54 by ogonzale         ###   ########.fr       */
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
			ft_choose_rotation(i, size_b, 'b', stck_b, instructions);
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

void	ft_prepare_stack(int key_a, t_stck **stck_b, int **instructions)
{
	int		size_b;
	int		i;

	size_b = (*stck_b)[0].size;
	if (size_b < 2)
		return ;
	if (ft_manage_extremes(key_a, stck_b, size_b, instructions) == 1)
		return ;
	i = 0;
	while (!((*stck_b)[size_b - i - 1].key > key_a
		&& (*stck_b)[size_b - i - 2].key < key_a))
		i++;
	while (!((*stck_b)[0].key > key_a && (*stck_b)[size_b - 1].key < key_a))
		ft_choose_rotation(i, size_b, 'b', stck_b, instructions);
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
		ft_choose_rotation(i, size_b, 'b', stck_b, instructions);
}

void	ft_loop_buckets(t_stck **stck_a, t_stck **stck_b, int size_a, int **instructions)
{
	int	num_buckets;
	int	num_per_bucket;
	int	j;
	int	pass;
	int	size;

	num_buckets = 0.015 * (*stck_a)[0].size + 3.5;
	num_per_bucket = (*stck_a)[0].size / num_buckets;
	ft_allocate_instructions(size_a, num_buckets, num_per_bucket, instructions); 
	j = 0;
	pass = -1;
	size = size_a;
	while (++pass < 2 * num_buckets + 1)
	{
		if (pass == (num_buckets + 1) / 2)
			num_per_bucket /= 2;
		while (j < num_per_bucket * (pass + 1) && (*stck_a)[0].size > 1)
		{
			size_a = (*stck_a)[0].size;
			if ((*stck_a)[size_a - 1].key < num_per_bucket * (pass + 1)
						&& (*stck_a)[size_a - 1].key != size - 1)
			{
				ft_prepare_stack((*stck_a)[size_a - 1].key, stck_b, instructions);
				ft_push('b', stck_a, stck_b, instructions);
				j++;
			}
			else
				ft_rotate('a', stck_a, instructions);
		}
	}
	ft_shift_stack(stck_b, instructions);
}

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	size_a;
	int	*instructions;

	size_a = (*stck_a)[0].size;
	ft_loop_buckets(stck_a, stck_b, size_a, &instructions);
	while ((*stck_b)[0].size > 0)
		ft_push('a', stck_a, stck_b, &instructions);
	ft_optimize_and_print_instructions(&instructions);
	free(instructions);
	if (ft_is_ordered(stck_a))
		printf("SUCCESS!\n");
	else
		printf("KO\n");
}
