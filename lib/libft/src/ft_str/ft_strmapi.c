/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:08:12 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 18:00:50 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_strmapi()
 * ----------------------
 * PARAMETERS:
 * 	s:	The string on which to iterate.
 * 	f:	The function to apply to each character.
 * RETURN: The string created from the successive applications of 'f'. Returns
 * NULL if the allocation fails.
 * DESCRIPTION: Applies the function 'f' to each character of the string 's',
 * and passing its index as first argument to create a new string (with 
 * malloc(3)) resulting from successive applications of 'f'.
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*f_s;
	unsigned int		i;

	if (!s || !f)
		return (0);
	f_s = ft_strdup(s);
	if (!f_s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		f_s[i] = f(i, f_s[i]);
		i++;
	}
	return (f_s);
}
