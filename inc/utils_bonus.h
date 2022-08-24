/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:49:48 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/24 13:03:37 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "push_swap.h"

# define ERR_READ	"Error reading the file"
# define ERR_WRITE	"Error writing to a file"
# define ERR_MEM	"Error allocating memory"
# define ERR_INST	"Error: used non-valid instruction"
# define ERROR		"Error"

/* utils.c */

void	terminate(char *s);
void	ft_allocate_stacks(t_stck **stck_a, t_stck **stck_b, int argc);
int		ft_is_ordered(t_stck **stck);

#endif
