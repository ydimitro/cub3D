/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:22:52 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:03:43 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_islowercase(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_islowercase(c))
	{
		c += 32;
		return (c);
	}
	return (c);
}

// int main(void) 
// {
//   char ch = ft_tolower('M');

//   printf("%c", ch);
//   return (0);
// }