/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:21:15 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/17 16:13:15 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_lstnew()
 * ---------------------
 * PARAMETERS:
 * 	content: The content to create the node with.
 * RETURN: The new node.
 * DESCRIPTION: Allocates (with malloc(3)) and returns a new node. The member
 * variable 'content' is initialized with the value of the parameter 'content'.
 * The variable 'next' is initialized to NULL.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
