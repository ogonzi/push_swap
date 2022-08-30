/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:21:21 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/30 18:09:21 by ogonzale         ###   ########.fr       */
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
# define RRA	6
# define RRB	7

typedef struct s_stck
{
	int	size;
	int	key;
	int	value;
}		t_stck;

typedef struct s_size
{
	int	a;
	int	b;
}		t_size;

typedef struct s_buckets
{
	int	count;
	int	num_per_bucket;
	int	pass;
	int	key;
	int	total_size;
}		t_buckets;

/* ft_atoi_mod.c */

int		ft_atoi_mod(const char *nptr);

/* parse.c */

void	ft_fill_stacks(int argc, char **argv, t_stck **stck_a,
			t_stck **stck_b);
void	ft_get_keys(t_stck **stck_a);

/* sort.c */

void	ft_sort(t_stck **stck_a, t_stck **stck_b);

/* operations.c */

void	ft_swap(char c, t_stck **stck, int **instructions);
void	ft_push(char c, t_stck **stck_a, t_stck **stck_b, int **instructions);
void	ft_rotate(char c, t_stck **stck, int **instructions);
void	ft_rev_rotate(char c, t_stck **stck, int **instructions);

/* large_sort.c */

void	ft_large_sort(t_stck **stck_a, t_stck **stck_b);

/* large_sort_2 */
void	ft_split_buckets(t_stck **stck_a, t_stck **stck_b, t_buckets *buckets,
			int **instructions);
#endif
