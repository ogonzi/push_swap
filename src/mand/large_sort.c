/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:16:51 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/20 12:38:46 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "libft.h"
#include <stdio.h>

void	ft_get_chunk_limitors(int **chunk_limitors, int num_chunks, t_stck **stck_a)
{
	t_stck	min;
	t_stck	max;
	int		range;
	int		interval;
	int		i;

	*chunk_limitors = malloc(sizeof(int) * (num_chunks - 1));
	if (!(*chunk_limitors))
		terminate(ERR_MEM);
	ft_get_min(&min, stck_a);
	ft_get_max(&max, stck_a);
	range = max.value - min.value;
	interval = range / num_chunks;
	printf("interval = %d\n", interval);
	i = 0;
	while (i < num_chunks - 1)
	{
		(*chunk_limitors)[i] = min.value + interval * (i + 1);
		printf("chunk limitor %d = %d\n", i, (*chunk_limitors)[i]);
		i++;
	}
}

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	size;
	int num_chunks;
	int	*chunk_limitors;

	if (ft_is_ordered(stck_a) == 1)
		return ;
	size = (*stck_a)[0].size;
	num_chunks = 0.015 * (float)size + 3.5;
	ft_get_chunk_limitors(&chunk_limitors, num_chunks, stck_a);
	free(chunk_limitors);
	stck_b[0]->size = 0;
}
