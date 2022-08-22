/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:20:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/22 11:09:37 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_min(t_stck *min, t_stck **stck)
{
	int		i;

	i = 0;
	*min = (*stck)[0];
	while (++i < (*stck)[0].size)
	{
		if ((*stck)[i].value < min->value)
			*min = (*stck)[i];
	}
}

void	ft_get_max(t_stck *max, t_stck **stck)
{
	int		i;

	i = 0;
	*max = (*stck)[0];
	while (++i < (*stck)[0].size)
	{
		if ((*stck)[i].value > max->value)
			*max = (*stck)[i];
	}
}

void	ft_choose_rotation(int pos, int size, char c, t_stck **stck)
{
	if (pos <= (size / 2))
		ft_rotate(c, stck);
	else
		ft_rev_rotate(c, stck);
}
