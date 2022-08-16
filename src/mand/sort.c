/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:05:10 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/16 20:44:39 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_stacks(t_stck **stck_a, t_stck **stck_b)
{
	int	i;

	printf("\ta: ");
	i = 0;
	while (i < (*stck_a)[0].size)
	{
		printf("%d ", (*stck_a)[i].value);
		i++;
	}
	printf("\n");
	printf("\tb: ");
	i = 0;
	while (i < (*stck_b)[0].size)
	{
		printf("%d ", (*stck_b)[i].value);
		i++;
	}
	printf("\n");
}

void	ft_sort(t_stck **stck_a, t_stck **stck_b)
{
	ft_print_stacks(stck_a, stck_b);	
	printf("sa\n");
	ft_swap(stck_a);
	ft_print_stacks(stck_a, stck_b);	
	printf("pb\n");
	ft_push('b', stck_a, stck_b);
	ft_print_stacks(stck_a, stck_b);
	printf("ra\n");
	ft_rotate(stck_a);
	ft_print_stacks(stck_a, stck_b);	
	printf("rra\n");
	ft_rev_rotate(stck_a);
	ft_print_stacks(stck_a, stck_b);	
}
