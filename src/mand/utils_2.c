/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:20:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/20 13:26:23 by ogonzale         ###   ########.fr       */
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
