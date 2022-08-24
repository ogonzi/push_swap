/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_instructions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:53:01 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/24 13:05:26 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "utils_bonus.h"
#include "get_next_line.h"

void	ft_choose_movement(char *instruction, t_stck **stck_a, t_stck **stck_b)
{
	int	len;

	len = ft_strlen(instruction);
	if (len > 4 || len < 3)
		terminate(ERR_INST);
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		ft_swap(stck_a);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		ft_swap(stck_b);

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
