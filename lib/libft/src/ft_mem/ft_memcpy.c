/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:40:56 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 11:19:26 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_memcpy()
 * ---------------------
 * PARAMETERS:
 * 	dest:	Pointer to destination memory area.
 * 	src:	Pointer to source memory area.
 * 	n:		Number of bytes to be copied.
 * RETURN: Pointer to dest.
 * DESCRIPTION: The ft_memcpy() function copies n bytes from memory area src
 * to memory area dest. The memory areas must not overlap. Use ft_memmove() if
 * the memory areas do overlap.
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
