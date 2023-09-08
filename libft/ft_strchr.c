/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:22:49 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:02:35 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(char *s, int c)
{
	unsigned char	ch;

	ch = c;
	while (*s)
	{
		if ((char)*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (0);
}

// int	main()
// {
// 	char	str[] = "teste";
// 	printf("%s\n", ft_strchr(str, 1024));
// 	printf("%s\n", strchr(str, 1024));
// }