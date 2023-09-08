/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:11:50 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:01:10 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

// Iterates the list ’lst’ and applies the function ’f’
// to the content of each element.
// Creates a new list resulting of
// the successive applications of the function ’f’.
// The ’del’ function is used to delete the content of an element if needed.
// Returns the new list. Null if the allocation fails.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_element;
	t_list	*new_list;

	new_list = 0;
	if ((*f) == 0 || (*del) == 0)
		return (0);
	while (lst != 0)
	{
		new_element = ft_lstnew((*f)(lst->content));
		if (!(new_element))
		{
			if (new_element != 0)
				ft_lstclear(&new_list, (*del));
			return (0);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
