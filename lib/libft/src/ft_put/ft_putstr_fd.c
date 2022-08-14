/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:55:36 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/07 10:14:53 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_putstr_fd()
 * ------------------------
 * PARAMETERS:
 * 	s:	The string to output.
 * 	fd:	The file descriptor on which to write.
 * RETURN: None.
 * DESCRIPTION: Outputs the string 's' to the given file descriptor.
 */

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
