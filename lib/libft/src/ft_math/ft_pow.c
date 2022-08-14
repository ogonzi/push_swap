/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:50:58 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 12:19:16 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * FUNCTION: ft_pow()
 * ------------------
 * PARAMETERS:
 * 	n: 		Base number.
 * 	pow:	Exponent.
 * RETURN: The value n raised to the power of y.
 * DESCRIPTION: A simplified version of pow(3). It is applied recursively with
 * the base case being that any number to the power of 0 is 1.
 */

long double	ft_pow(long double n, unsigned int pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_pow(n, pow - 1));
}
