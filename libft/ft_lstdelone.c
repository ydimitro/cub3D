/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:11:23 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:00:59 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

// Takes as a parameter an element and frees the memory of the element’s content
// using the function ’del’ and free the element.

void	ft_lstdelone(t_list *lst, void (*del) (void*))
{
	(*del)(lst -> content);
	free(lst);
}
