/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/30 18:24:22 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * [ft_manage_extremes]
 * If the value to push is an extreme, b is rotated appropiately and 1
 * is returned.
 * If it is not an extreme, 0 is returned and nothing is done.
 */

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

/*
 * [ft_prepare_and_push]
 * Firstly the cases if size_b < 2 and if the pushed value is an extreme in
 * b are handleled.
 * Seconly the number of positions from the top of b to the future position
 * of the value to push are calculated (i).
 * Lastly, the most appropiate rotation is chosen so that the value is pushed
 * to the correct location.
 */

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

/*
 * [ft_shift_stack] 
 * Ensures that the minimum value is on top of stack b,
 * performing the most efficient rotation to accomplish it.
 */

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

/*
 * [ft_loop_buckets]
 * The number of buckets is dependant on the size of the stack. 
 * If the size is larger than 125 then the buckets are split into quarters,
 * this number is chosen since for less than this cutoff the splitting is not
 * worth it.
 * For each pass, if the key pertains to the bucket, it is pushed to the correct
 * location in b (some movements are usually necessary in b).
 * If not, a is rotated.
 */

void	ft_loop_buckets(t_stck **stck_a, t_stck **stck_b, int size_a,
			int **instructions)
{
	t_buckets	buckets;

	buckets.count = ft_get_buckets_count(size_a);
	buckets.num_per_bucket = size_a / buckets.count;
	ft_allocate_instructions(size_a, buckets.count, buckets.num_per_bucket,
		instructions);
	buckets.key = 0;
	buckets.pass = -1;
	buckets.total_size = size_a;
	if (buckets.total_size > 125)
		ft_split_buckets(stck_a, stck_b, &buckets, instructions);
	while (++buckets.pass < buckets.count + 1)
	{
		while (buckets.key < buckets.num_per_bucket * (buckets.pass + 1)
			&& (*stck_a)[0].size > 2)
		{
			size_a = (*stck_a)[0].size;
			if ((*stck_a)[size_a - 1].key
						< buckets.num_per_bucket * (buckets.pass + 1)
						&& (*stck_a)[size_a - 1].key < buckets.total_size - 2)
				ft_prepare_and_push(stck_a, stck_b, instructions, &buckets.key);
			else
				ft_rotate('a', stck_a, instructions);
		}
	}
}

/*
 * [ft_large_sort]
 * 	1. 	Find the keys corresponding to a bucket, push to b while sorting, repeat.
 * 	2. 	Once all keys (except max and max - 1) are in b, shift b so max is on top
 * 		and push to a.
 * 	3.	An optimizing function is used to check if ra and rb appear consecutively
 * 		and replace them with the appropiate number of rr.
 */

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	size_a;
	int	*instructions;

	size_a = (*stck_a)[0].size;
	ft_loop_buckets(stck_a, stck_b, size_a, &instructions);
	ft_shift_stack(stck_b, &instructions);
	if ((*stck_a)[1].value > (*stck_a)[0].value)
		ft_swap('a', stck_a, &instructions);
	while ((*stck_b)[0].size > 0)
		ft_push('a', stck_a, stck_b, &instructions);
	ft_optimize_and_print_instructions(&instructions);
	free(instructions);
}
