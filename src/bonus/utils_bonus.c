/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:48:43 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/24 17:20:59 by ogonzale         ###   ########.fr       */
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

int	ft_check_combo(char *instruction, t_stck **stck_a, t_stck **stck_b)
{
	if (ft_strncmp(instruction, "ss\n", 3) == 0)
	{
		ft_swap(stck_a);
		ft_swap(stck_b);
		return (1);
	}
	if (ft_strncmp(instruction, "rr\n", 3) == 0)
	{
		ft_rotate(stck_a);
		ft_rotate(stck_b);
		return (1);
	}
	if (ft_strncmp(instruction, "rrr\n", 4) == 0)
	{
		ft_rev_rotate(stck_a);
		ft_rev_rotate(stck_b);
		return (1);
	}
	return (0);
}
