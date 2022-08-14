/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:18:18 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 19:55:32 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_calloc()
 * ---------------------
 * PARAMETERS:
 * 	number:	Elements of the array
 * 	size:	Size in bytes of each element
 * RETURN: Pointer to the allocated memory
 * DESCRIPTION: The ft_calloc() function allocated memory for an array of
 * number elements of size bytes each and returns a function to the allocated
 * memory. The memory is set to zero (see ft_memset()). If total_size == 0 or 
 * total_size overflows, calloc returns NULL.
 */

void	*ft_calloc(size_t number, size_t size)
{
	void	*dst;
	size_t	total_size;

	total_size = size * number;
	dst = malloc(total_size);
	if (!dst)
		return (0);
	ft_memset(dst, 0, total_size);
	return (dst);
}
