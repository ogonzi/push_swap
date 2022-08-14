/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:55:20 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/17 12:20:32 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_toupper()
 * ----------------------
 * PARAMETERS:
 * 	c:	The character to convert.
 * RETURN: The converted letter, or c if the conversion was not possible.
 * DESCRIPTION: The function ft_toupper() converts lowercase letters to 
 * uppercase.
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
		return (c);
	}
	return (c);
}
