/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:12:43 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 12:15:42 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_numsize()
 * ----------------------
 * PARAMETERS:
 * 	n:	Int to check size
 * RETURN: The number of digits n has.
 * DESCRIPTION: The function ft_numsize() counts the number of digits a given
 * number has. The '-' is counted as a digit.
 */

int	ft_numsize(int n)
{
	int	num_size;

	num_size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		num_size++;
	while (n != 0)
	{
		num_size++;
		n = n / 10;
	}
	return (num_size);
}
