/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:20:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/23 10:10:25 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "utils.h"

void	ft_get_limits(t_stck *min, t_stck *max, t_stck **stck)
{
	int		i;

	i = 0;
	*min = (*stck)[0];
	*max = (*stck)[0];
	while (++i < (*stck)[0].size)
	{
		if ((*stck)[i].value < min->value)
			*min = (*stck)[i];
		if ((*stck)[i].value > max->value)
			*max = (*stck)[i];
	}
}

void	ft_choose_rotation(int pos, int size, char c, t_stck **stck, int **instructions)
{
	if (pos <= (size / 2))
		ft_rotate(c, stck, instructions);
	else
		ft_rev_rotate(c, stck, instructions);
}

void	ft_save_instruction(int code, int **instructions)
{
	int	i;

	i = 0;
	while ((*instructions)[i] != -1)
		i++;
	(*instructions)[i] = code;
}

void	ft_optimize_and_print_instructions(int **instructions)
{
	int	i;
	int	count_ra;
	int	count_rb;

	i = 0;
	while ((*instructions)[i] != -1)
	{
		if ((*instructions)[i] == SA)
			ft_printf("sa\n");
		else if ((*instructions)[i] == SB)
			ft_printf("sb\n");
		else if ((*instructions)[i] == PA)
			ft_printf("pa\n");
		else if ((*instructions)[i] == PB)
			ft_printf("pb\n");
		else if ((*instructions)[i] == RB)
			ft_printf("rb\n");
		else if ((*instructions)[i] == RRA)
			ft_printf("rra\n");
		else if ((*instructions)[i] == RRB)
			ft_printf("rrb\n");
		else if ((*instructions)[i] == RA)
		{
			count_ra = 0;
			while ((*instructions)[i] == RA)
			{
				count_ra++;
				i++;
			}
			count_rb = 0;
			while ((*instructions)[i] == RB)
			{
				count_rb++;
				i++;
			}
			i--;
			while (count_ra > 0 && count_rb > 0)
			{
				ft_printf("rr\n");
				count_ra--;
				count_rb--;
			}
			while (count_ra > 0)
			{
				ft_printf("ra\n");
				count_ra--;
			}
			while (count_rb > 0)
			{
				ft_printf("rb\n");
				count_rb--;
			}
		}
		i++;
	}
}
