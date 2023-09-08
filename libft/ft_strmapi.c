/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:09:39 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/18 02:51:25 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*str;
	char	*temp_s;

	temp_s = (char *)s;
	i = 0;
	if (!temp_s || !f)
		return (0);
	len = ft_strlen(temp_s);
	(str = (char *)malloc(sizeof(char) * (len + 1)));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = (*f)(i, temp_s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char f(int i, char c)
// {
// 	char str;
// 	str = c + 1;
// 	return (str);
// }
// int main()
// {
// 	char str1[] = "abcd";
// 	char* str2;
// 	str2 = ft_strmapi(str1, *f);
// 	printf("%s\n", str2);
// }