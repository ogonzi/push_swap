/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:20:36 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/18 12:06:04 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_lstmap()
 * ---------------------
 * PARAMETERS:
 * 	lst:	The address of a pointer to a node.
 * 	f:		The address of the function used to iterate on the list.
 * 	del:	The address of the function used to delete the content of a node if
 * 			needed.
 * RETURN: The new list. NULL if the allocation fails.
 * DESCRIPTION: Iterates the list 'lst' and applies the function 'f' on the
 * content of each node. Creates a new list resulting of the successive
 * applications of the function 'f'. The 'del' function is used to delete the
 * content of a node if needed.
 * DEV: A loop through the input lst list is run. For each iteration a node
 * 'elem' is created (see ft_lstnew()) using the function 'f'. If the elem
 * allocation fails, the list is cleared and NULL is returned. Else, the elem
 * node is added to the back of the new list.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_lst;
	t_list	*elem;
	t_list	*temp;

	if (!lst)
		return (0);
	f_lst = 0;
	while (lst)
	{
		temp = f(lst->content);
		elem = ft_lstnew(temp);
		if (!elem)
		{
			ft_lstclear(&f_lst, del);
			del(temp);
			return (0);
		}
		ft_lstadd_back(&f_lst, elem);
		lst = lst->next;
	}
	return (f_lst);
}
