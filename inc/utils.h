/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:49:48 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/16 12:34:38 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "push_swap.h"

# define ERR_READ	"Error reading the file"
# define ERR_WRITE	"Error writing to a file"
# define ERR_MEM	"Error allocating memory"
# define ERR_INT	"Number is larger than INT"
# define ERR_DIGIT	"Argument is not a number"
# define ERR_EMPTY	"Argument is empty"

/* utils.c */

void	terminate(char *s);
void	ft_allocate_stacks(t_stck **stck_a, t_stck **stck_b, int argc);
void	ft_free_stacks(t_stck **stck_a, t_stck **stck_b);
#endif
