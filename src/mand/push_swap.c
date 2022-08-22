/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:00:53 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/22 12:59:53 by ogonzale         ###   ########.fr       */
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
	int		*instructions;

	if (argc == 1)
		return (0);
	instructions = NULL;
	ft_allocate_stacks(&stck_a, &stck_b, argc);
	ft_fill_stacks(argc, argv, &stck_a, &stck_b);
	ft_get_keys(&stck_a);
	ft_sort(&stck_a, &stck_b, &instructions);
	ft_free_stacks(&stck_a, &stck_b);
	if (instructions != NULL)
		free(instructions);
	return (0);
}
