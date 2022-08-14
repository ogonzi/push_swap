/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:22:53 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/01 13:17:05 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_base10_int(va_list ap, t_flags *flags)
{
	int	n;
	int	printed_len;

	n = va_arg(ap, int);
	printed_len = 0;
	if (flags->plus && n >= 0)
		ft_putstr_mod_fd("+", 1, flags, &printed_len);
	else if (flags->space && n >= 0)
		ft_putstr_mod_fd(" ", 1, flags, &printed_len);
	ft_putnbr_mod_fd(n, 1, flags, &printed_len);
	return (printed_len);
}

int	ft_print_unsigned(va_list ap, t_flags *flags)
{
	unsigned int	n;
	int				printed_len;

	n = va_arg(ap, unsigned int);
	printed_len = 0;
	ft_putunbr_base(n, "0123456789", flags, &printed_len);
	return (printed_len);
}
