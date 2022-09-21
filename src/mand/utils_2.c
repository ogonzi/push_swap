/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:20:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/09/21 14:47:07 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_choose_rotation(int pos, char c, t_stck **stck, int **instructions)
{
	int	size;

	size = (*stck)[0].size;
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

void	ft_handle_ra(int **instructions, int *i)
{
	t_count	count;

	count.ra = 0;
	while ((*instructions)[*i] == RA)
	{
		count.ra++;
		(*i)++;
	}
	count.rb = 0;
	while ((*instructions)[*i] == RB)
	{
		count.rb++;
		(*i)++;
	}
	(*i)--;
	while (count.ra > 0 && count.rb > 0)
	{
		ft_printf("rr\n");
		count.ra--;
		count.rb--;
	}
	while (count.ra-- > 0)
		ft_printf("ra\n");
	while (count.rb-- > 0)
		ft_printf("rb\n");
}

void	ft_optimize_and_print_instructions(int **instructions)
{
	int	i;

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
			ft_handle_ra(instructions, &i);
		i++;
	}
}
