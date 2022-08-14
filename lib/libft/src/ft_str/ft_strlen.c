/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:18:28 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 17:58:35 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_strlen()
 * ---------------------
 * PARAMETERS:
 * 	s:	The string to calculate the length on.
 * RETURN: The number of bytes in the string pointed to by s.
 * DESCRIPTION: The ft_strlen() function calculates the length of the string
 * pointed to by s, excluding the terminating null byte ('\0').
 */

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
