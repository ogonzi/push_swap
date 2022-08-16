/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:46:13 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/16 17:47:39 by ogonzale         ###   ########.fr       */
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
			terminate(ERR_DUPL);
		j++;
	}
}

void	ft_fill_stacks(int argc, char **argv, t_stck **stck_a, t_stck **stck_b)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		(*stck_a)[i].size = argc - 1;
		(*stck_a)[i].key = i;
		(*stck_a)[i].value = ft_atoi_mod(argv[i + 1]);
		ft_check_duplicate(stck_a, i);
		(*stck_b)[i].size = 0;
		(*stck_b)[i].key = i;
		(*stck_b)[i].value = 0;
		i++;
	}
}
