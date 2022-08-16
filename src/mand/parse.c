/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:46:13 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/16 11:55:56 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_parse_input(int argc, char **argv, t_stck **stck_a)
{
	int	i;

	*stck_a = malloc(sizeof(t_stck) * (argc - 1));
	if (!(*stck_a))
		terminate(ERR_MEM);
	i = 0;
	while (i < argc - 1)
	{
		(*stck_a)[i].key = i;
		(*stck_a)[i].value = ft_atoi_mod(argv[i + 1]);
		i++;
	}
}
