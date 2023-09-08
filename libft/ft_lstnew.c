/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:11:57 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/18 02:57:38 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//Allocates and returns a new element.
t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (0);
	new_element->content = content;
	new_element->next = 0;
	return (new_element);
}

// int main(void)
// {
// 	char	str [] = "Hello world";
// 	t_list		*new_element;
// 	if (!(new_element = ft_lstnew(str)))
// 				return(0);
// 		else
// 		{
// 			if (!(new_element->content))
// 				return(0);
// 			else
// 			{
// 				printf("%s", new_element->content);
// 			}
// 			if (!(new_element->next))
// 			{
// 				printf("\n");
// 				return(0);
// 			}
// 		}	
// }
