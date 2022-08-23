/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:32:06 by ogonzale          #+#    #+#             */
/*   Updated: 2022/08/23 08:52:36 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "ft_printf.h"

void	ft_swap(char c, t_stck **stck, int **instructions)
{
	t_stck	tmp;
	int		size;

	size = (*stck)[0].size;
	if (size < 2)
		return ;
	tmp.value = (*stck)[size - 1].value;
	tmp.key = (*stck)[size - 1].key;
	(*stck)[size - 1].value = (*stck)[size - 2].value;
	(*stck)[size - 1].key = (*stck)[size - 2].key;
	(*stck)[size - 2].value = tmp.value;
	(*stck)[size - 2].key = tmp.key;
	if (instructions == NULL)
		ft_printf("s%c\n", c);
	else if (instructions != NULL && c == 'a')
		ft_save_instruction(SA, instructions);
	else if (instructions != NULL && c == 'b')
		ft_save_instruction(SB, instructions);
}

void	ft_push(char c, t_stck **stck_a, t_stck **stck_b, int **instructions)
{
	int	size_a;
	int	size_b;

	size_a = (*stck_a)[0].size;
	size_b = (*stck_b)[0].size;
	if (c == 'b')
	{
		if (size_a == 0)
			return ;
		(*stck_b)[size_b].value = (*stck_a)[size_a - 1].value;
		(*stck_b)[size_b].key = (*stck_a)[size_a - 1].key;
		(*stck_b)[0].size++;
		(*stck_a)[0].size--;
	}
	else if (c == 'a')
	{
		if (size_b == 0)
			return ;
		(*stck_a)[size_a].value = (*stck_b)[size_b - 1].value;
		(*stck_a)[size_a].key = (*stck_b)[size_b - 1].key;
		(*stck_a)[0].size++;
		(*stck_b)[0].size--;
	}
	if (instructions == NULL)
		ft_printf("p%c\n", c);
	else if (instructions != NULL && c == 'a')
		ft_save_instruction(PA, instructions);
	else if (instructions != NULL && c == 'b')
		ft_save_instruction(PB, instructions);
}

void	ft_rotate(char c, t_stck **stck, int **instructions)
{
	t_stck	tmp;
	int		size;
	int		i;

	size = (*stck)[0].size;
	i = size;
	tmp.value = (*stck)[size - 1].value;
	tmp.key = (*stck)[size - 1].key;
	while (--i >= 0)
	{
		if (i == 0)
		{
			(*stck)[i].value = tmp.value;
			(*stck)[i].key = tmp.key;
		}
		else
		{
			(*stck)[i].value = (*stck)[i - 1].value;
			(*stck)[i].key = (*stck)[i - 1].key;
		}
	}
	if (instructions == NULL)
		ft_printf("r%c\n", c);
	else if (instructions != NULL && c == 'a')
		ft_save_instruction(RA, instructions);
	else if (instructions != NULL && c == 'b')
		ft_save_instruction(RB, instructions);
}

void	ft_rev_rotate(char c, t_stck **stck, int **instructions)
{
	t_stck	tmp;
	int		size;
	int		i;

	size = (*stck)[0].size;
	i = -1;
	tmp.value = (*stck)[0].value;
	tmp.key = (*stck)[0].key;
	while (++i < size)
	{
		if (i == size - 1)
		{
			(*stck)[i].value = tmp.value;
			(*stck)[i].key = tmp.key;
		}
		else
		{
			(*stck)[i].value = (*stck)[i + 1].value;
			(*stck)[i].key = (*stck)[i + 1].key;
		}
	}
	if (instructions == NULL)
		ft_printf("rr%c\n", c);
	else if (instructions != NULL && c == 'a')
		ft_save_instruction(RRA, instructions);
	else if (instructions != NULL && c == 'b')
		ft_save_instruction(RRB, instructions);
}
