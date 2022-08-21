/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/21 10:59:12 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdio.h>

void	ft_prepare_bucket(int key_a, t_stck **stck_b)
{
	int	i;
	int		size_b;
	t_stck	min;
	t_stck	max;
	
	size_b = (*stck_b)[0].size;
	if (size_b < 2)
		return ;
	ft_get_min(&min, stck_b);
	ft_get_max(&max, stck_b);
	if (key_a < min.key || key_a > max.key)
		return ;
	i = 0;
	while ((*stck_b)[size_b - i - 1].key > key_a)
		i++;
	while ((*stck_b)[size_b - 1].key > key_a)
	{
		if (i <= size_b / 2)
			ft_rotate('b', stck_b);
		else
			ft_rev_rotate('b', stck_b);
	}

}

void	ft_process_bucket(t_stck **stck_b)
{
	int	size_b;

	size_b = (*stck_b)[0].size;
	if (size_b < 2)
		return ;
	while ((*stck_b)[size_b - 1].value < (*stck_b)[0].value)
		ft_rotate('b', stck_b);
}

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	num_buckets;
	int	num_per_bucket;
	int	size_a;
	int	i;
	int	j;

	num_buckets = 0.015 * (*stck_a)[0].size + 3.5;
	num_per_bucket = (*stck_a)[0].size / num_buckets;
	i = 0;
	j = 0;
	while (j < num_per_bucket)
	{
		size_a = (*stck_a)[0].size;
		if ((*stck_a)[size_a - 1].key < num_per_bucket)
		{
			ft_prepare_bucket((*stck_a)[size_a - 1].key, stck_b);
			ft_push('b', stck_a, stck_b);
			ft_process_bucket(stck_b);
			j++;
		}
		else
			ft_rotate('a', stck_a);
		i++;
	}
}
