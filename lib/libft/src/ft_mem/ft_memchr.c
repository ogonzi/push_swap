/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 07:58:33 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 11:10:47 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_memchr()
 * ---------------------
 * PARAMETERS:
 * 	s:	Pointer to memory area to be searched.
 * 	c:	Character to be found.
 * 	n:	Number of bytes to be scanned.
 * RETURN: A pointer to the matching byte or NULL if the character does not
 * occur in the given memory area.
 * DESCRIPTION: The ft_memchr() function scans the initial n bytes of the
 * memory area pointer to by s for the first instance of c. Both c and the 
 * bytes of the memory area pointer to by s are interpreted as unsigned char.
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == ((unsigned char *)s)[i])
			return ((unsigned char *)(s + i));
		i++;
	}
	return (0);
}
