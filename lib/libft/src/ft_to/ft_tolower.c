/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:55:20 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/17 12:21:01 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_tolower()
 * ----------------------
 * PARAMETERS:
 * 	c:	The character to convert.
 * RETURN: The converted letter, or c if the conversion was not possible.
 * DESCRIPTION: The function ft_tolower() converts uppercase letters to
 * lowercase. 
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
		return (c);
	}
	return (c);
}
