/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:05:10 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/17 11:27:21 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "utils.h"

void	ft_print_stacks(t_stck **stck_a, t_stck **stck_b)
{
	int	i;

	ft_printf("\ta: ");
	i = 0;
	while (i < (*stck_a)[0].size)
	{
		ft_printf("%d ", (*stck_a)[i].value);
		i++;
	}
	ft_printf("\n");
	ft_printf("\tb: ");
	i = 0;
	while (i < (*stck_b)[0].size)
	{
		ft_printf("%d ", (*stck_b)[i].value);
		i++;
	}
	ft_printf("\n");
}

void	ft_sort_two(t_stck **stck_a)
{
	if ((*stck_a)[0].value < (*stck_a)[1].value)
		ft_swap('a', stck_a);
}

void	ft_sort_three(t_stck **stck_a)
{
	if (((*stck_a)[0].value < (*stck_a)[1].value) &&
			(*stck_a)[1].value < (*stck_a)[2].value)
	{
		ft_rotate('a', stck_a);
		ft_swap('a', stck_a);
	}
	else if (((*stck_a)[0].value < (*stck_a)[1].value) &&
			(*stck_a)[1].value > (*stck_a)[2].value &&
			(*stck_a)[0].value > (*stck_a)[2].value)
	{
		ft_rev_rotate('a', stck_a);
		ft_swap('a', stck_a);
	}
	else if (((*stck_a)[0].value < (*stck_a)[1].value) &&
			(*stck_a)[1].value > (*stck_a)[2].value &&
			(*stck_a)[0].value < (*stck_a)[2].value)
		ft_rev_rotate('a', stck_a);
	else if (((*stck_a)[0].value > (*stck_a)[1].value) &&
			(*stck_a)[1].value < (*stck_a)[2].value &&
			(*stck_a)[0].value > (*stck_a)[2].value)
		ft_swap('a', stck_a);
	else if (((*stck_a)[0].value > (*stck_a)[1].value) &&
			(*stck_a)[1].value < (*stck_a)[2].value &&
			(*stck_a)[0].value < (*stck_a)[2].value)
		ft_rotate('a', stck_a);
}

void	ft_sort_four(t_stck **stck_a, t_stck **stck_b)
{
	int		i;
	t_stck	min;

	i = 0;
	min = (*stck_a)[0];
	while (++i < (*stck_a)[0].size)
	{
		if ((*stck_a)[i].value < min.value)
			min = (*stck_a)[i];
	}
	if (min.key == 0)
		ft_rev_rotate('a', stck_a);
	else if (min.key == 1)
	{
		ft_rev_rotate('a', stck_a);
		ft_rev_rotate('a', stck_a);
	}
	else if (min.key == 2)
		ft_rotate('a', stck_a);
	if (ft_is_ordered(stck_a) == 0)
	{
		ft_push('b', stck_a, stck_b);
		ft_sort_three(stck_a);
		ft_push('a', stck_a, stck_b);
	}
}

void	ft_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	size;

	size = (*stck_a)[0].size;
	if (size == 1)
		return ;
	else if (size == 2)
		ft_sort_two(stck_a);
	else if (size == 3)
		ft_sort_three(stck_a);
	else if (size == 4)
		ft_sort_four(stck_a, stck_b);
	/*
	else if (size == 5)
		ft_sort_five(stck_a, stck_b);
	else
		ft_sort_large(stck_a, stck_b);
	*/
	ft_print_stacks(stck_a, stck_b);
}
