/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:45:18 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 19:25:37 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_get_size()
 * -----------------------
 * PARAMETERS:
 * s:		The string from which to create the substring.
 * start:	The start index of the substring in the string 's'.
 * len:		The maximum length of the substring.
 * RETURN: The necessary allocation space.
 * DESCRIPTION: The function ft_get_size() takes into account the different
 * possible combinations between the three parameters and returns the 
 * corresponding size for each case.
 */

static size_t	ft_get_size(char const *s, unsigned int start, size_t len)
{
	if (start >= ft_strlen(s))
		return (1);
	if (start < ft_strlen(s) && (ft_strlen(s) - start) < len)
		return (ft_strlen(s) - start + 1);
	if (len < ft_strlen(s))
		return (len + 1);
	if (len >= ft_strlen(s))
		return (ft_strlen(s) + 1);
	return (0);
}

/*
 * FUNCTION: ft_substr()
 * ---------------------
 * PARAMETERS:
 * 	s:		The string from which to create the substring.
 * 	start:	The start index of the substring in the string 's'.
 * 	len:	The maximum length of the substring.
 * RETURN: The substring. NULL if the allocation fails.
 * DESCRIPTION: Allocates (with malloc(3)) and returns a substring from
 * the string 's'. The substring begins at index 'start' and is of maximum 
 * size 'len'.
 * DEV: Since there are 3 variables that can determine the size of
 * necessary memory a function (ft_get_size) is used to determine the size.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	size;

	size = ft_get_size(s, start, len);
	sub_s = malloc(size);
	if (!sub_s)
		return (0);
	if (start >= ft_strlen(s))
	{
		sub_s[0] = '\0';
		return (sub_s);
	}
	i = start;
	while (i < start + size - 1)
	{
		sub_s[i - start] = s[i];
		i++;
	}
	sub_s[i - start] = '\0';
	return (sub_s);
}
/*
int	main(void)
{
	char	*res;
	size_t	num;

	res = ft_substr("hola", 0, 0);
	printf("%s\n", res);
	return (0);
}
*/
