/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:50:35 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/01 13:18:04 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_hex(va_list ap, char c, t_flags *flags)
{
	int					printed_len;
	unsigned int		hex;

	printed_len = 0;
	hex = va_arg(ap, unsigned int);
	if (c == 'x')
	{
		if (flags->hashtag && hex)
			ft_putstr_mod_fd("0x", 1, flags, &printed_len);
		ft_putunbr_base(hex, "0123456789abcdef", flags, &printed_len);
	}
	else if (c == 'X')
	{
		if (flags->hashtag && hex)
			ft_putstr_mod_fd("0X", 1, flags, &printed_len);
		ft_putunbr_base(hex, "0123456789ABCDEF", flags, &printed_len);
	}
	return (printed_len);
}

int	ft_print_address(va_list ap, t_flags *flags)
{
	int					printed_len;
	unsigned long int	addr;

	printed_len = 0;
	addr = va_arg(ap, unsigned long int);
	ft_putstr_mod_fd("0x", 1, flags, &printed_len);
	ft_putunbr_base(addr, "0123456789abcdef", flags, &printed_len);
	return (printed_len);
}
