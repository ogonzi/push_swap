/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:21:21 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/24 16:55:58 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

typedef struct s_stck
{
	int	size;
	int	value;
}		t_stck;

/* ft_atoi_mod_bonus.c */

int		ft_atoi_mod(const char *nptr);

/* parse_bonus.c */

void	ft_fill_stacks(int argc, char **argv, t_stck **stck_a,
			t_stck **stck_b);

/* follow_instructions_bonus.c */

void	ft_follow_instructions(t_stck **stck_a, t_stck **stck_b);

/* operations_bonus.c */

void	ft_swap(t_stck **stck);
void	ft_push(t_stck **to, t_stck **from);
void	ft_rotate(t_stck **stck);
void	ft_rev_rotate(t_stck **stck);

#endif
