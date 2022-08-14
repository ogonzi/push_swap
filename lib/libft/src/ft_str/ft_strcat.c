/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:02:15 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 17:28:11 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * FUNCTION: ft_strcat()
 * ---------------------
 * PARAMETERS:
 * 	src:	The source string.
 * 	dest:	The destination string.
 * RETURN: A pointer to the resulting string dest.
 * DESCRIPTION: The ft_strcat() function appends the src string to the dest
 * string, overwritting the terminating null byte ('\0') at the end of dest,
 * and then adds a terminating null byte. The strings may not overlap, and the
 * dest string must have enough space for the result.
 */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
