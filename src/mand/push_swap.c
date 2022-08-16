/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:00:53 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/16 11:23:28 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stck *stck_a;

	if (argc == 1)
		return(0);
	ft_parse_input(argc, argv, &stck_a);
	int	i = -1;
	while (++i < argc - 1)
		printf("%d ", stck_a[i].value);
	free(stck_a);
	return (0);
}
