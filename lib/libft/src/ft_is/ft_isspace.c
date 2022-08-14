/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:44:09 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 19:59:02 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_isspace()
 * ----------------------
 * PARAMETERS:
 * 	c:	Unsigned char to check
 * RETURN: The value returned is nonzero (1) if the char c falls into the
 * tested class, and zero if not.
 * DESCRIPTION: Checks for white-space characters. In the "C" and "POSIX"
 * locales, these are: space, form-feed ('\f'), newline ('\n'), carriage
 * return ('\r'), horizontal tab ('\t') and vertical tab ('\v')..
 */

int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}
