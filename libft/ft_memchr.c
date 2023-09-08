/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:18:05 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:01:21 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//The memchr() function locates the first occurrence of 
//c (converted to an unsigned char) in string s.

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *) s;
	ch = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (0);
}

//int main() {
//	const char str[] = "Hello World";
//	const char ch = 'l';
//	char *ret;
//	
//	ret = ft_memchr(str, ch, strlen(str));
//	printf("My function:\nString after |%c| is - |%s|\n\n", ch, ret);
//
//	ret = memchr(str, ch, strlen(str));
//	printf("Real function:\nString after |%c| is - |%s|\n\n", ch, ret);
//
//	return(0);
//}
