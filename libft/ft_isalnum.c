/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:17:01 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:00:24 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//function tests for any character for which isalpha or isdigit is true. 

int	ft_isalnum(int x)
{
	if (ft_isalpha(x) || ft_isdigit(x))
		return (1);
	return (0);
}

//int	main()
//{
//	char c;
//
//	c = '2';
//	printf("Alphabet: %d", ft_isalnum(c));
//	return (0);
//}