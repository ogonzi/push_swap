/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:00:15 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 17:56:31 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_strlcpy()
 * ----------------------
 * PARAMETERS:
 * 	dst:	The destination string.
 * 	src:	The source string.
 * 	size:	The number of bytes to bound.
 * RETURN: The total length of the string it tried to create. Therefore, the
 * length of src.
 * DESCRIPTION: The ft_strlcpy() copies up to size - 1 characters from the
 * NULL-terminated string src to dst, NULL-terminating the result.
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	len;
	unsigned int	index;

	len = 0;
	index = 0;
	while (src[len] != '\0')
		len++;
	if (size != 0)
	{
		while (src[index] != '\0' && index < (size - 1))
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (len);
}
