/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:16:51 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/18 10:31:07 by ogonzale         ###   ########.fr       */
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

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	size;

	size = (*stck_a)[0].size;
	ft_split_by_sign(stck_a, stck_b, size);	
	ft_split_stack(stck_a, stck_b);
}
