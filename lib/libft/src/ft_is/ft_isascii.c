/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:53:27 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 19:56:42 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_isascii()
 * ----------------------
 * PARAMETERS:
 * 	c:	Unsigned char to check
 * RETURN: The value returned is nonzero (1) if the char c falls into the
 * tested class, and zero if not.
 * DESCRIPTION: Checks whether c is a 7-bit unsigned char value that fits into
 * the ASCII character set.
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
