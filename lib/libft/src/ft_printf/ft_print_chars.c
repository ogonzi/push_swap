/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:27:35 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/01 13:17:33 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_char(va_list ap, char c, t_flags *flags)
{
	if (c == 'c')
		ft_putchar_mod_fd((unsigned char)va_arg(ap, int), 1, flags);
	else if (c == '%')
		ft_putchar_mod_fd('%', 1, flags);
	return (1);
}

int	ft_print_string(va_list ap, t_flags *flags)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	len = 0;
	if (!str)
		len = ft_print_null(flags);
	else
		ft_putstr_mod_fd(str, 1, flags, &len);
	return (len);
}
