/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:01:42 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/01 13:19:07 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_handle_edge_cases(char *base)
{	
	int	i;

	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
	}
	if (i < 2)
		return (0);
	return (1);
}

static int	ft_print_num(unsigned long int nbr, int i, char *base,
			t_flags *flags)
{
	int	j;
	int	num_arr[64];
	int	printed_len;

	printed_len = 0;
	j = -1;
	while (++j < 64)
	{
		num_arr[j] = nbr % i;
		nbr = nbr / i;
	}
	j--;
	while (num_arr[j] == 0)
		j--;
	if (j == -2)
		j = 0;
	while (j >= 0)
	{
		if (num_arr[j] < 0)
			num_arr[j] = -num_arr[j];
		ft_putchar_mod_fd(base[num_arr[j]], 1, flags);
		printed_len++;
		j--;
	}
	return (printed_len);
}

void	ft_putunbr_base(unsigned long int nbr, char *base, t_flags *flags,
			int *printed_len)
{
	int	i;
	int	j;

	if (ft_handle_edge_cases(base) == 0)
		return ;
	i = -1;
	while (base[++i] != '\0')
	{
		j = i;
		while (base[++j] != '\0')
		{
			if (base[j] == base[i])
				return ;
		}
	}
	if (nbr == 0)
	{
		ft_putchar_mod_fd(base[0], 1, flags);
		*printed_len += 1;
		return ;
	}
	*printed_len += ft_print_num(nbr, i, base, flags);
}

int	ft_print_null(t_flags *flags)
{
	int	printed_len;

	printed_len = 0;
	ft_putstr_mod_fd("(null)", 1, flags, &printed_len);
	return (printed_len);
}
