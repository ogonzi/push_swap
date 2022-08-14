/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:20:42 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 17:37:42 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_strdup()
 * ---------------------
 * PARAMETERS:
 * 	str:	The string to duplicate.
 * RETURN: A pointer to a new string which is a duplicate of the string str or
 * NULL if the allocation failed.
 * DESCRIPTION: The ft_strdup() function returns a pointer to a new string 
 * which is a duplicate of the string s. Memory for the new string is obtained
 * with malloc(3).
 */

char	*ft_strdup(const char *str)
{
	int		len;
	char	*str_cpy;
	int		i;

	len = ft_strlen(str);
	str_cpy = (char *)malloc(len * sizeof(char) + 1);
	if (!str_cpy)
		return (0);
	i = -1;
	while (str[++i] != '\0')
		str_cpy[i] = str[i];
	str_cpy[i++] = '\0';
	return (str_cpy);
}
