/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:22:55 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:03:47 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_islowercase(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_islowercase(c))
	{
		c -= 32;
		return (c);
	}
	return (c);
}

// int main(void) 
// {
//   char ch = ft_toupper('m');

//   printf("%c", ch);
//   return (0);
// }