/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:17:49 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:03:18 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//function computes the length of the string s.

size_t	ft_strlen(const char *str)
{
	size_t	count;
	char	*tempstr;

	tempstr = (char *)str;
	count = 0;
	while (tempstr[count])
	{
		count++;
	}
	return (count);
}

//int main(void)
//{
//	char *test = "Something to test";
//	char *test1 ="";
//	char *test2 ="Something \0";
//
//	printf("The first size: %d\n", ft_strlen(test));
//	printf("The second size: %d\n", ft_strlen(test1));
//	printf("The third size: %d\n", ft_strlen(test2));
//}