/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:26:18 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:01:52 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*x;

	x = b;
	while (len > 0)
	{
		*x = c;
		x++;
		len--;
	}
	return (b);
}

//int	main(void)
//{
//	char str[] = "Hello";
//	printf("%s", ft_memset(str, 'a', 3));
//	return (0);
//}