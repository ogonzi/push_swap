/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:05:10 by ogonzale          #+#    #+#             */
/*   Updated: 2022/09/21 14:44:26 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils.h"

void	ft_sort_two(t_stck **stck_a)
{
	if ((*stck_a)[0].value < (*stck_a)[1].value)
		ft_swap('a', stck_a, 0);
}

void	ft_sort_three(t_stck **stck_a)
{
	if (((*stck_a)[0].value < (*stck_a)[1].value) &&
			(*stck_a)[1].value < (*stck_a)[2].value)
	{
		ft_rotate('a', stck_a, 0);
		ft_swap('a', stck_a, 0);
	}
	else if (((*stck_a)[0].value < (*stck_a)[1].value) &&
			(*stck_a)[1].value > (*stck_a)[2].value &&
			(*stck_a)[0].value > (*stck_a)[2].value)
	{
		ft_rev_rotate('a', stck_a, 0);
		ft_swap('a', stck_a, 0);
	}
	else if (((*stck_a)[0].value < (*stck_a)[1].value) &&
			(*stck_a)[1].value > (*stck_a)[2].value &&
			(*stck_a)[0].value < (*stck_a)[2].value)
		ft_rev_rotate('a', stck_a, 0);
	else if (((*stck_a)[0].value > (*stck_a)[1].value) &&
			(*stck_a)[1].value < (*stck_a)[2].value &&
			(*stck_a)[0].value > (*stck_a)[2].value)
		ft_swap('a', stck_a, 0);
	else if (((*stck_a)[0].value > (*stck_a)[1].value) &&
			(*stck_a)[1].value < (*stck_a)[2].value &&
			(*stck_a)[0].value < (*stck_a)[2].value)
		ft_rotate('a', stck_a, 0);
}

void	ft_sort_four(t_stck **stck_a, t_stck **stck_b)
{
	int	min_key;

	min_key = 0;
	if ((*stck_b)[0].size == 1)
		min_key = 1;
	if ((*stck_a)[0].key == min_key)
		ft_rev_rotate('a', stck_a, 0);
	else if ((*stck_a)[1].key == min_key)
	{
		ft_rotate('a', stck_a, 0);
		ft_swap('a', stck_a, 0);
	}
	else if ((*stck_a)[2].key == min_key)
		ft_swap('a', stck_a, 0);
	if (ft_is_ordered(stck_a) == 0)
	{
		ft_push('b', stck_a, stck_b, 0);
		ft_sort_three(stck_a);
		ft_push('a', stck_a, stck_b, 0);
	}
}

void	ft_sort_five(t_stck **stck_a, t_stck **stck_b)
{
	if ((*stck_a)[0].key == 0)
		ft_rev_rotate('a', stck_a, 0);
	else if ((*stck_a)[1].key == 0)
	{
		ft_rev_rotate('a', stck_a, 0);
		ft_rev_rotate('a', stck_a, 0);
	}
	else if ((*stck_a)[2].key == 0)
	{
		ft_rotate('a', stck_a, 0);
		ft_swap('a', stck_a, 0);
	}
	else if ((*stck_a)[3].key == 0)
		ft_swap('a', stck_a, 0);
	if (ft_is_ordered(stck_a) == 0)
	{
		ft_push('b', stck_a, stck_b, 0);
		ft_sort_four(stck_a, stck_b);
		ft_push('a', stck_a, stck_b, 0);
	}
}

void	ft_sort(t_stck **stck_a, t_stck **stck_b)
{
	int	size;

	if (ft_is_ordered(stck_a) == 1)
		return ;
	size = (*stck_a)[0].size;
	if (size == 1)
		return ;
	else if (size == 2)
		ft_sort_two(stck_a);
	else if (size == 3)
		ft_sort_three(stck_a);
	else if (size == 4)
		ft_sort_four(stck_a, stck_b);
	else if (size == 5)
		ft_sort_five(stck_a, stck_b);
	else
		ft_large_sort(stck_a, stck_b);
}
