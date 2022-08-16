/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:47:30 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/16 11:57:32 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	ft_check_empty(const char *nptr, int *i)
{
	while (ft_isspace(nptr[*i]) || nptr[*i] == '\0')
	{
		if (nptr[*i] == '\0')
			terminate(ERR_EMPTY);
		(*i)++;
	}
}

void	ft_get_sign(const char *nptr, int *neg, int *i)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*neg = 1;
		(*i)++;
	}
}

void	ft_check_digit(const char *nptr, int *i)
{
	while (nptr[*i] != '\0')
	{
		if (ft_isdigit(nptr[*i]) == 0)
			terminate(ERR_DIGIT);
		(*i)++;
	}
}

int	ft_atoi_mod(const char *nptr)
{
	int		i;
	long	res;
	int		neg;
	int		start_num;

	i = 0;
	res = 0;
	neg = 0;
	ft_check_empty(nptr, &i);
	ft_get_sign(nptr, &neg, &i);
	start_num = i - 1;
	ft_check_digit(nptr, &i);
	while (++start_num < i)
		res = res + (nptr[start_num] - '0') * ft_pow(10, i - start_num - 1);
	if (neg == 1)
		res = -res;
	if (res > 2147483647 || res < -2147483648)
		terminate(ERR_INT);
	return ((int)res);
}
