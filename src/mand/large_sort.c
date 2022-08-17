/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:16:51 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/17 17:20:51 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	num_buckets;
	int	nums_per_bucket;

	num_buckets = (*stck_a)[0].size / 50;
	nums_per_bucket =
}
