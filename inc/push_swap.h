/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:21:21 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/17 10:03:37 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stck
{
	int	size;
	int	key;
	int	value;
}		t_stck;

/* ft_atoi_mod.c */

int		ft_atoi_mod(const char *nptr);

/* parse.c */

void	ft_fill_stacks(int argc, char **argv, t_stck **stck_a,
			t_stck **stck_b);

/* sort.c */

void	ft_sort(t_stck **stck_a, t_stck **stck_b);

/* operations.c */

void	ft_swap(char c, t_stck **stck);
void	ft_push(char c, t_stck **stck_a, t_stck **stck_b);
void	ft_rotate(char c, t_stck **stck);
void	ft_rev_rotate(char c, t_stck **stck);
#endif
