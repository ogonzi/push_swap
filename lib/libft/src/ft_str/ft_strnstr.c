/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:38:47 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 18:11:57 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_strnstr()
 * ----------------------
 * PARAMETERS:
 * 	str:		The string to be searched on.
 * 	to_find:	The string to be found.
 * 	n:			The maximum number of bytes to seach on.
 * RETURN: If to_find is an empty string, str is returned; if to_find occurs
 * nowhere in str, NULL is returned; otherwisee a pointer to the first
 * character of the first occurrence of to_find is returned.
 * DESCRIPTION: The ft_strnstr() function locates the first occurrence of the 
 * null-terminated string to_find in the string str, where no more than n 
 * characters are searched. Characters that appear after a '\0' are not
 * searched.
 */

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < n)
		{
			if (str[i + j] == '\0' && to_find[j] == '\0')
				return ((char *)(str + i));
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)(str + i));
		i++;
	}	
	return (0);
}
