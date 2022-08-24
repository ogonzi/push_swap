/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:48:43 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/24 12:00:32 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "utils_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

void	ft_allocate_stacks(t_stck **stck_a, t_stck **stck_b, int argc)
{
	*stck_a = malloc(sizeof(t_stck) * (argc - 1));
	if (!(*stck_a))
		terminate(ERR_MEM);
	*stck_b = malloc(sizeof(t_stck) * (argc - 1));
	if (!(*stck_b))
		terminate(ERR_MEM);
}

void	ft_allocate_instructions(int size, int num_buckets, int size_buckets,
			int **instructions)
{
	int	theoretical_limit;
	int	i;

	i = 0;
	theoretical_limit = 0;
	while (i < num_buckets)
	{
		theoretical_limit += size - i * size_buckets;
		i++;
	}
	theoretical_limit += size * (1 + size_buckets / 2);
	if (theoretical_limit < 100)
		theoretical_limit = 100;
	*instructions = malloc(sizeof(int) * theoretical_limit);
	if (*instructions == NULL)
		terminate(ERR_MEM);
	i = 0;
	while (i < theoretical_limit)
	{
		(*instructions)[i] = -1;
		i++;
	}
}

int	ft_is_ordered(t_stck **stck)
{
	int	i;

	i = 0;
	while (++i < (*stck)[0].size)
	{
		if ((*stck)[i].value > (*stck)[i - 1].value)
			return (0);
	}
	return (1);
}
