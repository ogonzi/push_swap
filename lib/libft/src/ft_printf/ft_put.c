/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:53:12 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/01 13:16:32 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_putchar_mod_fd(char c, int fd, t_flags *flags)
{
	flags->err = write(fd, &c, 1);
}

void	ft_putstr_mod_fd(char *s, int fd, t_flags *flags, int *printed_len)
{
	int	i;

	if (!s)
	{
		flags->err = -1;
		return ;
	}
	i = -1;
	while (s[++i] != '\0')
	{
		ft_putchar_mod_fd(s[i], fd, flags);
		if (flags->err == -1)
			return ;
		*printed_len += 1;
	}
}

void	ft_putnbr_mod_fd(int n, int fd, t_flags *flags, int *printed_len)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_mod_fd('-', fd, flags);
		*printed_len = *printed_len + 1;
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_mod_fd(nb / 10, fd, flags, printed_len);
	ft_putchar_mod_fd(nb % 10 + '0', fd, flags);
	*printed_len = *printed_len + 1;
}
