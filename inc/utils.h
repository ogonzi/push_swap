/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:49:48 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/22 20:24:38 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

# define ERR_READ	"Error reading the file"
# define ERR_WRITE	"Error writing to a file"
# define ERR_MEM	"Error allocating memory"
# define ERROR		"Error"

/* utils.c */

void	terminate(char *s);
void	ft_allocate_stacks(t_stck **stck_a, t_stck **stck_b, int argc);
void	ft_allocate_instructions(int size, int num_buckets, int size_buckets,
			int **instructions);
void	ft_free_stacks(t_stck **stck_a, t_stck **stck_b);
int		ft_is_ordered(t_stck **stck);

/* utils_2.c */

void	ft_get_min(t_stck *min, t_stck **stck);
void	ft_get_max(t_stck *max, t_stck **stck);
void	ft_choose_rotation(int pos, int size, char c, t_stck **stck, int **instructions);
void	ft_save_instruction(int code, int **instructions);
void	ft_optimize_and_print_instructions(int **instructions);

#endif
