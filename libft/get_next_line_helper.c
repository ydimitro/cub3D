/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:21:45 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/18 23:41:26 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_gnl_strlen(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_gnl_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		x;
	int		j;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1)));
	if (!str)
		return (NULL);
	x = -1;
	j = 0;
	if (s1)
	{
		while (s1[++x] != '\0')
			str[x] = s1[x];
	}
	while (s2[j] != '\0')
		str[x++] = s2[j++];
	str[ft_gnl_strlen(s1) + ft_gnl_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
