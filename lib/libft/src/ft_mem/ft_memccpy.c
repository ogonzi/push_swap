/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:27:38 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 11:07:20 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_memccpy()
 * ----------------------
 * PARAMETERS:
 * 	dest:	Pointer to destination memory area.
 * 	src:	Pointer to source memory area.
 * 	c:		Character that limits copy if found.
 * 	n:		Size in bytes to copy.
 * RETURN: A pointer to the next character in dest after c, or NULL if c was
 * not found in the first n characters of src.
 * DESCRIPTION: The ft_memccpy() function copies no more than n bytes from
 * memory area src to memory area dest, stopping when the character c is found.
 * If the memory areas overlap, the results are undefined.
 */

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char buff1[] = "abcdefghijklmnopqrstuvwxyz";
	char buff2[] = "abcdefghijklmnopqrstuvwxyz";
	char *src = "string with\200inside !";

	__builtin___memccpy_chk
	(buff1, src, 0600, 21, __builtin_object_size (buff1, 0));
    ft_memccpy(buff2, src, 0600, 21);
    if (!ft_memcmp(buff1, buff2, 21))
        write(1, "success\n", 9);
    write(1, "failed\n", 8);
	printf("%s\n", buff1);
	printf("%s\n", buff2);
	return (0);
}
*/
