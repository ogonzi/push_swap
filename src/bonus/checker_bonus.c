/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:00:53 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/24 12:35:26 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "utils_bonus.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stck	*stck_a;
	t_stck	*stck_b;

	if (argc == 1)
		return (0);
	ft_allocate_stacks(&stck_a, &stck_b, argc);
	ft_fill_stacks(argc, argv, &stck_a, &stck_b);
	ft_follow_instructions(stck_a, stck_b);
	if (ft_is_ordered(stck_a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(stck_a);
	free(stck_b);
	return (0);
}
