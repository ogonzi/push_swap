/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:22:53 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/16 19:26:51 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stck **stck)
{
	int	tmp;
	int	size;

	size = (*stck)[0].size;
	tmp = (*stck)[size - 1].value;
	(*stck)[size - 1].value = (*stck)[size - 2].value;
	(*stck)[size - 2].value = tmp;
}
