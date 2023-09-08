/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:59:52 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:00:27 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//The isalpha() function tests for any character for which the alphabet
//	(Capital letters or not) is true.

int	ft_isalpha(int x)
{
	if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
		return (1);
	return (0);
}

//int	main()
//{
//	int c;
//
//	c = 130;
//	printf("Alphabet: %i", ft_isalpha(c));
//	return (0);
//}
