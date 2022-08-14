/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:16:38 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 18:03:53 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_strncmp()
 * ----------------------
 * PARAMETERS:
 * 	s1:	The first string to be compared.
 * 	s2:	The second string to be compared.
 * 	n:	The maximum number of bytes to compare.
 * RETURN: an integer less than, equal to, or greater than zero if s1 (or the
 * first n bytes thereof) is found, respectively, to be less than, to match,
 * or be greater than s2.
 * DESCRIPTION: Similar to ft_strcmp(), except is compares only the first n 
 * bytes of s1 and s2.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				cmp;
	unsigned int	i;

	cmp = 0;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	cmp = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (cmp);
}
