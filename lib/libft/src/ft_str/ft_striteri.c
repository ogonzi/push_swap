/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:54:04 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 17:39:44 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_striteri()
 * -----------------------
 * PARAMETERS:
 * 	s:	The string on which to iterate.
 * 	f:	The function to apply to each character.
 * RETURN: None.
 * DESCRIPTION: Applies the function 'f' on each character of the string
 * passed as argument, passing its index as first argument. Each character is
 * passed by address to 'f' to be modified if necessary.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
