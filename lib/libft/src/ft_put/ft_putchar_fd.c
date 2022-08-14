/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:53:25 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 12:20:38 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_putchar_fd()
 * -------------------------
 * PARAMETERS:
 * 	c:	The character to output.
 * 	fd:	The file descriptor on which to write.
 * RETURN: None.
 * DESCRIPTION: Outputs the character 'c' to the give file descriptor.
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
