/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:21:21 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/16 11:07:59 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stck
{
	int	key;
	int	value;
}		t_stck;

/* ft_atoi_mod.c */

int	ft_atoi_mod(const char *nptr);

/* parse.h */

void	ft_parse_input(int argc, char **argv, t_stck **stck_a);
#endif
