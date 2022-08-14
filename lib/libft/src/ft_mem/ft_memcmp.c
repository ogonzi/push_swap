/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:16:38 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 11:17:06 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_memcmp()
 * ---------------------
 * PARAMETERS:
 * 	s1:	Pointer to the first memory area.
 * 	s2: Pointer to the second memory area.
 * 	n:	Number of bytes to be scanned.
 * RETURN: An integer less than, equal to, or greater than zero if the first
 * n bytes of s1 is found, respectively, to be less than, to match, or be
 * greater than the first n bytes of s2. For a nonzero return value, the sign
 * is determined by the sign of the difference between the first pair of bytes
 * (interpreted as unsigned char) that differ in s1 and s2. If n is zero, the 
 * return value is zero.
 * DESCRIPTION: The ft_memcmp() function compares the first n bytes (each
 * interpreted as unsigned char) of the memory areas s1 and s2.
 * DEV: The while loop has two conditions, and exits if either one of them is
 * met. Either n - 1 is reached, meaning the compairason of the next byte must
 * be the result, or s1 and s2 differ at some point before that.
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				cmp;
	unsigned int	i;

	cmp = 0;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && ((unsigned char *)s1)[i] ==
			((unsigned char *)s2)[i])
		i++;
	cmp = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (cmp);
}
