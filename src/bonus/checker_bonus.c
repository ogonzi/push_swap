/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:00:53 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/24 11:58:47 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "utils_bonus.h"
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
	ft_get_keys(&stck_a);
	ft_sort(&stck_a, &stck_b);
	free(stck_a);
	free(stck_b);
	return (0);
}
