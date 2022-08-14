/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:24:09 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/18 11:14:35 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_itoa()
 * -------------------
 * PARAMETERS:
 * 	n: The integer to convert.
 * RETURN: The string representing the integer. NULL if the allocation fails.
 * DESCRIPTION: Allocates (with malloc(3)) and returns a string representing
 * the integer received as an argument. Negative numbers must be handled.
 */

char	*ft_itoa(int n)
{
	int		num_size;
	int		i;
	int		div;
	char	*num;

	num_size = ft_numsize(n);
	num = malloc(sizeof(char) * (num_size + 1));
	if (!num)
		return (0);
	i = 0;
	if (n < 0)
	{
		num[i] = '-';
		num_size--;
		i++;
	}
	div = ft_pow(10, num_size - 1);
	while (div >= 1)
	{
		num[i++] = ft_abs_value(n / div) + '0';
		n = n % div;
		div /= 10;
	}
	num[i] = '\0';
	return (num);
}
