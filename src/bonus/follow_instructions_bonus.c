/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_instructions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:53:01 by ogonzale          #+#    #+#             */
/*   Updated: 2022/09/21 14:55:02 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"
#include "get_next_line.h"
#include "libft.h"

int	ft_check_rotate(char *instruction, t_stck **stck_a, t_stck **stck_b)
{
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
	{
		ft_rotate(stck_a);
		return (1);
	}
	if (ft_strncmp(instruction, "rb\n", 3) == 0)
	{
		ft_rotate(stck_b);
		return (1);
	}
	if (ft_strncmp(instruction, "rra\n", 4) == 0)
	{
		ft_rev_rotate(stck_a);
		return (1);
	}
	if (ft_strncmp(instruction, "rrb\n", 4) == 0)
	{
		ft_rev_rotate(stck_b);
		return (1);
	}
	return (0);
}

int	ft_check_push(char *instruction, t_stck **stck_a, t_stck **stck_b)
{
	if (ft_strncmp(instruction, "pa\n", 3) == 0)
	{
		ft_push(stck_a, stck_b);
		return (1);
	}
	if (ft_strncmp(instruction, "pb\n", 3) == 0)
	{
		ft_push(stck_b, stck_a);
		return (1);
	}
	return (0);
}

int	ft_check_swap(char *instruction, t_stck **stck_a, t_stck **stck_b)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
	{
		ft_swap(stck_a);
		return (1);
	}
	if (ft_strncmp(instruction, "sb\n", 3) == 0)
	{
		ft_swap(stck_b);
		return (1);
	}
	return (0);
}

void	ft_choose_movement(char *instruction, t_stck **stck_a, t_stck **stck_b)
{
	if (ft_check_swap(instruction, stck_a, stck_b) == 1)
		return ;
	if (ft_check_push(instruction, stck_a, stck_b) == 1)
		return ;
	if (ft_check_rotate(instruction, stck_a, stck_b) == 1)
		return ;
	if (ft_check_combo(instruction, stck_a, stck_b) == 1)
		return ;
	terminate(ERR_INST);
}

void	ft_follow_instructions(t_stck **stck_a, t_stck **stck_b)
{
	char	*instruction;

	instruction = get_next_line(STDIN_FILENO);
	while (instruction != NULL)
	{
		ft_choose_movement(instruction, stck_a, stck_b);
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
}
