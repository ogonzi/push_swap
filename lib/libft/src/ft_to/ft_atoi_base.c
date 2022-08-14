/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:14:49 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 19:54:39 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION ft_power_of_base()
 * ---------------------------
 * PARAMETERS:
 * 	i:		The index correspoding to he significance of the digit.
 * 	base:	The string representing the base.
 * 	c:		The character to use.
 * RETURN: The value of the i-th digit.
 * DESCRIPTION: The function ft_power_of_base() gets the power corresponding 
 * to the significance of the digit (for example, in base10, the 4th digit has
 * a corresponding power of 1000). Then it multiplies the previous result times
 * the corresponding position of the character in the base.
 */

static int	ft_power_of_base(int i, char *base, char c)
{
	int	j;
	int	power_of_base;
	int	base_size;

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	power_of_base = 1;
	j = -1;
	while (++j < (i - 1))
		power_of_base = power_of_base * base_size;
	j = -1;
	while (base[++j] != 0)
	{
		if (c == base[j])
			power_of_base = power_of_base * j;
	}
	return (power_of_base);
}

/*
 * FUNCTION: ft_handle_edge_cases()
 * --------------------------------
 * PARAMETERS:
 * 	base:	The string representing the base.
 * RETURN: Nonzero value if the base is valid, zero otherwise.
 * DESCRIPTION: Checks if the base is valid (doesn't contain '+' or '-', 
 * doesn't contain repeating characters, and it's length is larger than
 * 2.
 */

static int	ft_handle_edge_cases(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[++j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
		}
	}
	if (i < 2)
		return (0);
	return (1);
}

/*
 * FUNCTION: ft_check_and_transform_num()
 * --------------------------------------
 * PARAMETERS:
 * 	str:	The string to convert.
 * 	base:	The string (base) to use.
 * 	neg:	The flag for the sign.
 * 	i:		The position in which the number starts.
 * RETURN: The number in the corresponding base.
 * DESCRIPTION: The function ft_check_and_transform_num() transforms the
 * number in base10 contained in str to an int in the specified base.
 * DEV: A counter is set to the beggining of the number in str.
 * The other counter (i) is advanced to the end of the number in str. Then,
 * a loop is performed starting from the most significant digit until the 
 * least significant digit.
 */

static int	ft_check_and_transform_num(char *str, char *base,
			int neg, int i)
{
	int	counter;
	int	res;

	counter = i - 1;
	res = 0;
	while ((ft_is_in_set(str[i], base) == 1) && str[i] != '\0')
		i++;
	while (++counter < i)
		res = res + ft_power_of_base(i - counter, base, str[counter]);
	if (neg == 1)
		res = -res;
	return (res);
}

/*
 * FUNCTION: ft_atoi_base()
 * ------------------------
 * PARAMETERS: 
 * 	str:	The string to be converted.
 * 	base:	The base to which convert. (ex. binary -> base = "01").
 * RETURN: The converted number in the appropiate base.
 * DESCRIPTION: Similar to ft_atoi(), in this case it converts the string
 * to a number in the defined base.
 * DEV: Checks are performed to determine if the base is valid in
 * ft_handle_edge_cases(): non-repeating characters, no '+' or '-', and 
 * not smaller than 2 characters.
 */

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 0;
	while (ft_isspace(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	if (ft_handle_edge_cases(base) == 0)
		return (0);
	res = ft_check_and_transform_num(str, base, neg, i);
	return (res);
}
