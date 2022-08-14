/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:52:31 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/27 13:11:36 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.width = 0;
	flags.hashtag = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.err = 0;
	return (flags);
}

static int	ft_get_flag(t_flags *flags, char c)
{
	if (c == '#')
		flags->hashtag = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == '.')
		flags->dot = 1;
	else
		return (0);
	return (1);
}	

static int	ft_conv_format(va_list ap, char c, t_flags *flags)
{
	int		printed_len;

	printed_len = 0;
	if (c == 'c' || c == '%')
		printed_len = ft_print_char(ap, c, flags);
	else if (c == 's')
		printed_len = ft_print_string(ap, flags);
	else if (c == 'd' || c == 'i')
		printed_len = ft_print_base10_int(ap, flags);
	else if (c == 'u')
		printed_len = ft_print_unsigned(ap, flags);
	else if (c == 'p')
		printed_len = ft_print_address(ap, flags);
	else if (c == 'x' || c == 'X')
		printed_len = ft_print_hex(ap, c, flags);
	if (flags->err == -1)
		return (-1);
	return (printed_len);
}

static int	ft_handle_flags_and_conv(const char *str, unsigned int *i,
			va_list ap, int *print_length)
{
	int		tmp_print_length;
	t_flags	flags;

	flags = ft_init_flags();
	while (ft_get_flag(&flags, str[*i + 1]) == 1)
		*i += 1;
	tmp_print_length = ft_conv_format(ap, str[*i + 1], &flags);
	if (tmp_print_length == -1)
		return (0);
	*print_length += tmp_print_length;
	*i += 1;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	va_list			ap;
	int				print_length;

	i = 0;
	print_length = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (!ft_handle_flags_and_conv(str, &i, ap, &print_length))
				return (-1);
		}
		else
		{
			if (write(1, &str[i], 1) == -1)
				return (-1);
			print_length++;
		}
		i++;
	}
	va_end(ap);
	return (print_length);
}
