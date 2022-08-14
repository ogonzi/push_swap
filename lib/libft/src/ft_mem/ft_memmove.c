/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:32:02 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 11:40:32 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_memmove()
 * ----------------------
 * PARAMETERS:
 * 	dest:	Pointer to destination memory area.
 * 	stc:	Pointer to source memory area.
 * 	n:		Number of bytes to be copied.
 * RETURN: Pointer to dest.
 * DESCRIPTION: The ft_memmove() function copies n bytes from memory area src
 * to memory area dest. The memory areas may overlap: copying takes place as
 * though the bytes in src are first copied into a temporary array that does not
 * overlap src or dest, and the bytes are then copied from the temporary array
 * to dest.
 * DEV: If the memory areas do not overlap (the address of the src pointer is
 * equal or larger than the address of dest) then ft_memcpy is used. 
 * If there is the possibility that the memory areas overlap (src < dest), then
 * the trick is to start from the end (n) and copy backwards. If it was done
 * the other way around, there would be the possibility that dest would be 
 * 'covered' by src. A simple drawing helps to understand this concept.
 */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	if ((size_t)src < (size_t)dest)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
		ft_memcpy((unsigned char *)dest, (unsigned char *)src, n);
	return (dest);
}
