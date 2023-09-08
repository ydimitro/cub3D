/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:09:36 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:02:59 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*pnt1;
	char	*pnt2;
	char	*result;

	pnt1 = (char *) s1;
	pnt2 = (char *) s2;
	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(pnt1);
	len2 = ft_strlen(pnt2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (0);
	ft_strcpy (result, pnt1);
	ft_strcpy (result + len1, pnt2);
	return (result);
}

// int		main(void)
// {
// 	char	*s1 = "Tatiana";
// 	char	*s2 = "Sofia";
// 	char	*strjoin;
// 	if (!(strjoin = ft_strjoin(s1, s2)))
// 			return(0);
// 	else
// 		printf("%s", strjoin);
// 	if (strjoin == s1 || strjoin == s2)
// 		printf("\nA new string was not returned");
// 	return(0);
// }
