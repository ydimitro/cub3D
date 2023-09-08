/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:09:41 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/18 02:50:16 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//this function removes the given char * "set" from the begining or end.
char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	char	*temp_s1;
	char	*temp_set;
	char	*str;

	temp_s1 = (char *)s1;
	temp_set = (char *)set;
	str = 0;
	if (temp_s1 != 0 && temp_set != 0)
	{
		front = 0;
		back = ft_strlen(temp_s1);
		while (temp_s1[front] && ft_strchr(temp_set, temp_s1[front]))
			front++;
		while (temp_s1[back - 1] && ft_strchr(temp_set,
				temp_s1[back - 1]) && back > front)
			back--;
		str = (char *)malloc(sizeof(char) * (back - front + 1));
		if (str)
			ft_strlcpy(str, &temp_s1[front], back - front + 1);
	}
	return (str);
}

// int main()
// {
// 	printf("%s\n", ft_strtrim("xhello Worldyz", "xyz"));
//     return 0;
// }