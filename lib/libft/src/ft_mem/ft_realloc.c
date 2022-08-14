/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:43:08 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/15 10:15:08 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_realloc()
 * ----------------------
 * PARAMETERS:
 * 	ptr:			Pointer to memory block.
 * 	original_size:	Original allocated size to ptr.
 * 	new_size:		New size to be allocated.
 * RETURN: A pointer to new memory block.
 * DESCRIPTION: A simplified version of realloc(3). In the case new_size != 0,
 * ptr != NULL and new_size is larger than original size, the function
 * ft_realloc() creates a new pointer and allocates new_size to it, then it
 * copies the contents of ptr to ptr_new using ft_memcpy() and frees ptr.
 */

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*ptr_new;

	if (new_size == 0)
	{
		free(ptr);
		return (0);
	}
	else if (!ptr)
		return (malloc(new_size));
	else if (new_size <= original_size)
		return (ptr);
	else
	{
		ptr_new = malloc(new_size);
		if (ptr_new)
		{
			ptr_new = ft_memcpy(ptr_new, ptr, original_size);
			free(ptr);
		}
		return (ptr_new);
	}
}
