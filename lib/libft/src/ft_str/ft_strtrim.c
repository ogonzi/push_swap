/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:25:57 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/18 11:05:48 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_one_empty_byte()
 * -----------------------------
 * PARAMETERS: None.
 * RETURN: Pointer to allocated memory.
 * DESCRIPTION: Allocates (with malloc(3)) a memory block of one byte and
 * initializes it to '\0'.
 */

static char	*ft_one_empty_byte(void)
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (0);
	s[0] = '\0';
	return (s);
}

/*
 * FUNCTION: ft_strtrim()
 * ----------------------
 * PARAMETERS:
 * 	s1:		The string to be trimmed.
 * 	set:	The reference set of character to trim.
 * RETURN: The trimmed string. NULL if the allocation fails.
 * DESCRIPTION: Allocates (with malloc(3)) and returns a copy of 's1'
 * with the characters specified in 'set' removed from the beginning 
 * and the end of the string.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		len;
	int		start;
	int		end;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	while (ft_is_in_set(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (ft_one_empty_byte());
	start = i;
	i = len - 1;
	while (ft_is_in_set(s1[i], set) && i >= 0)
		i--;
	end = i + 1;
	s = malloc((end - start + 1) * sizeof(char));
	if (!s)
		return (0);
	i = start - 1;
	while (++i < end)
		s[i - start] = s1[i];
	s[i - start] = '\0';
	return (s);
}
/*
int	main(void)
{
	char *s1 = "";
    char *ret = ft_strtrim(s1, "");

	printf("%s\n", ret);
	return (0);
}
*/
