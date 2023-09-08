/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:48:27 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:00:17 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//function erases the data in the n bytes of the memory
//starting at the location pointed to by s, by writing zeros (bytes
//containing '\0') to that area.

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
//void	printstr(char *str)
//{
//	int	i;
//	i=0;
//	while(i != 20)
//	{
//		char c = str[i];
//		write(1, &c, 1);
//		i++;
//	}
//}
//
//int	main()
//{
//	char str[20] = "ALOHAasddsad";
//	char str1[20] = "ALOHAasddsad";
//	ft_bzero(str, 6);
//	printf("%s\n", str);
//	printstr(str);
//	bzero(str1, 6);
//	printf("%s\n", str1);
//	printstr(str1);
//	return (0);
//}