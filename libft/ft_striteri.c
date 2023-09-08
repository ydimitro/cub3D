/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:09:32 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:02:56 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
	return ;
}

// void test(unsigned int i, char *c)
// {
// 	char *str;
// 	*str = *c + 1;
// }
// int main(void)  
// {
//    	char	*str;
// 	str = (char *)malloc(sizeof(*str) * 12);
// 	strcpy(str, "abc");
// 	ft_striteri(str, &test);
// 	printf("%s", str);
// 	return (0);
// }