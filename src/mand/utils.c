/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:48:43 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/17 11:25:27 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"
#include <stdlib.h>

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

void	ft_free_stacks(t_stck **stck_a, t_stck **stck_b)
{
	free(*stck_a);
	free(*stck_b);
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
