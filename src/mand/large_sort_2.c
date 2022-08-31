/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:50:44 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/31 09:56:15 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	ft_push_quarter_to_b(t_stck **stck_a, t_stck **stck_b,
			t_buckets buckets, int **instructions)
{
	int	i;
	int	size_a;

	i = -1;
	while (++i < buckets.total_size)
	{
		size_a = (*stck_a)[0].size;
		if ((*stck_a)[size_a - 1].key % buckets.num_per_bucket
				>= 3 * buckets.num_per_bucket / 4)
			ft_rotate('a', stck_a, instructions);
		else
			ft_push('b', stck_a, stck_b, instructions);
	}
}

void	ft_push_two_quarters_to_a(t_stck **stck_a, t_stck **stck_b,
			t_buckets buckets, int **instructions)
{
	int	i;
	int	quarter;
	int	size_b;

	quarter = 3;
	while (--quarter > 0)
	{
		i = -1;
		size_b = (*stck_b)[0].size;
		while (++i < size_b)
		{
			if ((*stck_b)[(*stck_b)[0].size - 1].key % buckets.num_per_bucket
					< quarter * buckets.num_per_bucket / 4)
				ft_rotate('b', stck_b, instructions);
			else
				ft_push('a', stck_a, stck_b, instructions);
		}
	}
}

void	ft_push_last_quarter_to_a(t_stck **stck_a, t_stck **stck_b,
			int **instructions)
{
	int	size_b;

	while ((*stck_b)[0].size > 2)
	{
		size_b = (*stck_b)[0].size;
		if ((*stck_b)[size_b - 1].key > 1)
			ft_push('a', stck_a, stck_b, instructions);
		else
			ft_rotate('b', stck_b, instructions);
	}
	if ((*stck_b)[1].value < (*stck_a)[0].value)
		ft_rotate('b', stck_b, instructions);
}

/*
 * [ft_split_buckets]
 * 	1.	Push the keys larger than 1/4 to b.
 * 	2.	Push the keys larger than 2/4 to a.
 * 	3.	Push the keys larger than 3/4 to a.
 * 	4.	Push the remaining keys to a, leaving the two smallest in b,
 * 		rotating appropietly.
 */

void	ft_split_buckets(t_stck **stck_a, t_stck **stck_b, t_buckets *buckets,
			int **instructions)
{
	ft_push_quarter_to_b(stck_a, stck_b, *buckets, instructions);
	ft_push_two_quarters_to_a(stck_a, stck_b, *buckets, instructions);
	ft_push_last_quarter_to_a(stck_a, stck_b, instructions);
	buckets->key += 2;
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
