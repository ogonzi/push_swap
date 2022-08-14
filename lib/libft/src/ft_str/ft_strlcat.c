/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:52:19 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 17:52:22 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_strlcat()
 * ----------------------
 * PARAMETERS: 
 * 	dst:	The destination string.
 * 	src:	The source string.
 * 	size:	The size to be bounded by.
 * RETURN: The total length of the string it tried to create. That means the
 * initial length of dst plus the length of src.
 * DESCRIPTION: The ft_strlcat() function appends the NULL-terminated string
 * src to the end of dst. It will append at most size - ft_strlen(dst) - 1 
 * bytes, NULL-terminating the result.
 * DEV: The ft_strlcat()  takes the full size of the buffer and guarantees to
 * NULL-terminate the result (as long as there is at least one byte free in 
 * dst). Note that a byte for the NULL should be included in size. 
 */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	j;
	unsigned int	i;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	j = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && j + 1 < size)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
