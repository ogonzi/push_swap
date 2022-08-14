/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:25:45 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 12:10:56 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_memset()
 * ---------------------
 * PARAMETERS:
 * 	s:	Pointer to memory area to be filled.
 * 	c:	Byte used to fill.
 * 	n:	Number of bytes to fill.
 * RETURN: A pointer to the memory area s.
 * DESCRIPTION: The ft_memset() function fills the first n bytes of the memory
 * area pointer to by s with the constant byte c.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
