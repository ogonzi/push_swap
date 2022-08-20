/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:46:13 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/20 13:51:52 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_check_duplicate(t_stck **stck_a, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if ((*stck_a)[i].value == (*stck_a)[j].value)
			terminate(ERROR);
		j++;
	}
}

void	ft_get_keys(t_stck **stck_a)
{
	int		i;
	int		j;
	int		k;
	int		min;

	j = 0;
	while (j < (*stck_a)[0].size)
	{
		k = 0;
		while ((*stck_a)[k].key >= 0)
			k++;
		min = (*stck_a)[k].value;
		while (++k < (*stck_a)[0].size)
		{
			if ((*stck_a)[k].value < min && (*stck_a)[k].key < 0)
				min = (*stck_a)[k].value;
		}
		i = 0;
		while (i < (*stck_a)[0].size)
		{
			if ((*stck_a)[i].value == min)
			{
				(*stck_a)[i].key = j;
				j++;
				break ;
			}
			i++;
		}
	}
}

void	ft_fill_stacks(int argc, char **argv, t_stck **stck_a, t_stck **stck_b)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (i == 0)
			(*stck_a)[i].size = argc - 1;
		else
			(*stck_a)[i].size = 0;
		(*stck_a)[i].key = -1;
		(*stck_a)[i].value = ft_atoi_mod(argv[argc - i - 1]);
		ft_check_duplicate(stck_a, i);
		(*stck_b)[i].size = 0;
		(*stck_b)[i].key = -1;
		(*stck_b)[i].value = 0;
		i++;
	}
}
