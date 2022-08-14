/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:19:44 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/17 13:19:49 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_lstclear()
 * -----------------------
 * PARAMETERS: 
 * 	lst: The address of a pointer to a node.
 * 	del: The address of the function used to delete the content of the node.
 * RETURN: None.
 * DESCRIPTION: Deletes and frees the given node and every successor of that
 * node, using the function 'del' and free(3). Finally, the pointer to the list
 * must be set to NULL.
 * DEV: A loop runs through the list lst, and for each iteration a temporal
 * node is created and set to the next node of the list. Then the current node
 * is deleted (see ft_lstdelone()), and lst is reset to tmp.
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = 0;
}
