/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:00:53 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/16 12:33:24 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
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
	ft_free_stacks(&stck_a, &stck_b);
	return (0);
}
