/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:21:29 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:01:26 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//The memcmp() function compares byte string s1 against byte string s2.  
//Both strings are assumed to be n bytes long.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*source1;
	unsigned char	*source2;

	source1 = (unsigned char *) s1;
	source2 = (unsigned char *) s2;
	while (n > 0)
	{
		if (*source1 != *source2)
			return (*source1 - *source2);
		source1++;
		source2++;
		n--;
	}
	return (0);
}
// void *  is a pointer that has no associated data type with it. 
// A void pointer can hold address of any type and can be typecasted to any type
// char * This is a string literal.
// '\200' Every char that is not a null terminator
// which one is a good practice? char str[] vs char *str ?

//int main () {
//	char str1[15];
// 	char str2[15];
//	int ret;
//
//	memcpy(str1, "ABCD", 6);
//	memcpy(str2, "abcd", 6);
//
//	ret = ft_memcmp(str1, str2, 5);
//	if(ret > 0) {
//		printf("str2 is less than str1\n");
//	} else if(ret < 0) {
//		printf("str1 is less than str2\n");
//	} else {
//		printf("str1 is equal to str2\n");
//	}
//
//	ret = memcmp(str1, str2, 5);
//	if(ret > 0) {
//		printf("From main function, str2 is less than str1\n");
//	} else if(ret < 0) {
//		printf("From main function, str1 is less than str2\n");
//	} else {
//		printf("From main function, str1 is equal to str2\n");
//	}
//	
//	return(0);
//}