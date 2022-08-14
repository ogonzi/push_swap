/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:37:13 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 19:56:54 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_isdigit()
 * ----------------------
 * PARAMETERS:
 * 	c:	Unsigned char to check
 * RETURN: The value returned is nonzero (1) if the char c falls into the
 * tested class, and zero if not.
 * DESCRIPTION: Checks for a digit (0 through 9).
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
