/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:40:42 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/18 03:25:14 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

// The strdup() function allocates sufficient memory for a copy 
// of the string s1, does the copy, and returns a pointer to it.  
// The pointer may subsequently be used as an argument to the function free(3).
// If insufficient memory is available, NULL is returned.
// The strndup() function copies at most n characters from the string s1 always 
// NUL terminating the copied string.

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	if (!(s1))
		return (NULL);
	while (s1[i] != '\0')
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// int main()
// {
//     char *source = "Hello World";
//     char* dest = ft_strdup(source);
//     printf("Destination -> %s\n", dest);
// 	printf("Destination -> %s\n", ft_strdup("Hello World"));
//     return 0;
// }	