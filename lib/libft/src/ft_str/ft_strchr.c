/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:58:53 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 17:32:34 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_strchr()
 * ---------------------
 * PARAMETERS:
 * 	s:	The string to be searched.
 * 	c:	The character to search.
 * RETURN: A pointer to the matched character or NULL if the character is not
 * found. The terminating null byte is considered part of the string, so that
 * if c is specified as '\0', this function returns a pointer to the 
 * terminator.
 * DESCRIPTION: The ft_strchr() function returns a pointer to the first 
 * occurence of the character c in the string s.
 * DEV: The if statement is added to account for the terminating null byte.
 */

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
