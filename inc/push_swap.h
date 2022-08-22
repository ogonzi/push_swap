/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:21:21 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/22 13:13:14 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA		0
# define SB		1
# define PA		2
# define PB		3
# define RA		4
# define RB		5
# define RR		6
# define RRA	7
# define RRB	8

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
void	ft_get_keys(t_stck **stck_a);

/* sort.c */

void	ft_sort(t_stck **stck_a, t_stck **stck_b, int **instructions);

/* operations.c */

void	ft_swap(char c, t_stck **stck, int **instructions);
void	ft_push(char c, t_stck **stck_a, t_stck **stck_b, int **instructions);
void	ft_rotate(char c, t_stck **stck, int **instructions);
void	ft_rev_rotate(char c, t_stck **stck, int **instructions);
void	ft_rr(t_stck **stck_a, t_stck **stck_b, int **instructions);

/* large_sort.c */

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b,
			int **instructions);

#endif
