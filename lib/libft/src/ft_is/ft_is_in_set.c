/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_set_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:34:10 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 19:55:56 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_is_in_set()
 * ------------------------
 * PARAMETERS:
 * 	c:		The char to check.
 * 	set:	The string to be checked.
 * RETURN: Nonzero (1) if found. Zero if not found.
 * DESCRIPTION: The ft_is_in_set() function checks if c is contained in s.
 */

int	ft_is_in_set(int c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
