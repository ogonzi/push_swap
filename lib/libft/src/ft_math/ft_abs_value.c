/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_value_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:37:33 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 19:30:04 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_abs_value()
 * ------------------------
 * PARAMETERS:
 * 	n: The number on which to compute the absolute value.
 * RETURN: The absolute value.
 * DESCRIPTION: Computes the absolute value of a number.
 */

size_t	ft_abs_value(long double n)
{
	if (n < 0)
		n = -n;
	return (n);
}
