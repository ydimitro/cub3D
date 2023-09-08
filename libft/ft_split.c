/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:09:28 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/18 03:21:30 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//Counts the number of times c appears on str
static int	counter(char *str, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			counter++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (counter);
}

char	**ft_split(char *s, char c)
{
	char	**splitted;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	splitted = malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!splitted)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			splitted[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	splitted[i] = 0;
	return (splitted);
}

// int main() 
// {
// 	char	**tabstr;
// 	int		i;
// 	tabstr = ft_split("       Hello world", ' ');
// 		while (tabstr[i] != NULL)
// 		{
// 			printf("%d = %s\n",i, tabstr[i]);
// 			i++;
// 		}
//    return 0;
// }