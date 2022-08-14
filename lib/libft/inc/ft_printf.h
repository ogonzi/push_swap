/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:05:43 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/04 16:59:03 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	width;
	int	hashtag;
	int	space;
	int	plus;
	int	err;
}	t_flags;

/* ft_printf.c */

int				ft_printf(const char *str, ...);

/* ft_print_chars.c */
int				ft_print_char(va_list ap, char c, t_flags *flags);
int				ft_print_string(va_list ap, t_flags *flags);

/* ft_print_hex.c */
int				ft_print_hex(va_list ap, char c, t_flags *flags);
int				ft_print_address(va_list ap, t_flags *flags);

/* ft_print_base10.c */
int				ft_print_base10_int(va_list ap, t_flags *flags);
int				ft_print_unsigned(va_list ap, t_flags *flags);

/* ft_utils.c */
int				ft_print_null(t_flags *flags);
void			ft_putunbr_base(unsigned long int nbr, char *base,
					t_flags *flags, int *printed_len);

/* ft_put.c */
void			ft_putchar_mod_fd(char c, int fd, t_flags *flags);
void			ft_putstr_mod_fd(char *s, int fd, t_flags *flags,
					int *printed_len);
void			ft_putnbr_mod_fd(int n, int fd, t_flags *flags,
					int *printed_len);
#endif
