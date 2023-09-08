/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:15:31 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/19 13:38:22 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//function compares not more than n characters.  
//Because strncmp() is designed for 
//comparing strings rather than binary data, characters that appear after a `\0'
//character are not compared.

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	x;

	x = 0;
	while ((s1[x] || s2[x]) && (x < n))
	{
		if (s1[x] != s2[x])
		{
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		}
		x++;
	}
	if (x == n)
		return (0);
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

// int main(void)
// {
// 	char *first = "hello";
// 	char *second = "hella";
// 	int decision;

// 	decision = strncmp(first, second, 10);
//    if (decision == 0) printf("They are equal\n");
//    if (decision > 0) printf("First string is greater than second\n");
// 	if (decision < 0) printf("Second string is greater than first\n");

// 	decision = ft_strncmp(first, second, 10);
// 	if (decision > 0)
// 		write(1, "First string is greater than second\n", 36);
// 	else 
// 	if (decision < 0)
// 		write(1, "Second string is greater than first\n", 36);
// 	else
// 		write(1, "They are equal\n", 15);
// }
