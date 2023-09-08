/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:09:45 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/18 02:49:17 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	if (!s)
		return (0);
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	while (s[++i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	str[] = "lorem ipsu\n";
// 	char	*strsub;
// 	int		arg;
// 	if (!(strsub = ft_substr(str, 0, 10)))
// 		return(0);
// 	else
// 		printf("%s", strsub);		
// 	if (str == strsub)
// 		printf("\nA new string was not returned");
// 	return(0);
// }