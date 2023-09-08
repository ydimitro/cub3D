/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:23:39 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:01:48 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (src == dest || len == 0)
		return (dest);
	if (dest < source)
	{
		return (ft_memcpy(dest, source, len));
	}
	else
	{
		while (len--)
		{
			dest[len] = source[len];
		}
	}		
	return (dest);
}

//int main () {
//   char dest[] = "hola";
//   const char src[]  = "mierda funciona";
//
//   printf("Before memmove:\n dest = %s, src = %s\n\n", dest, src);
//   memmove(dest, src, 3);
//   printf("After memmove:\n dest = %s, src = %s\n\n", dest, src);
//
//   ft_memmove(dest, src, 3);
//   printf("From my function, 
//	after memmove:\n dest = %s, src = %s\n\n", dest, src);
//
//   return(0);
//}