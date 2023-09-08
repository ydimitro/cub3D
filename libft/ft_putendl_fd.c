/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:09:19 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/05/17 23:02:04 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s++, fd);
	}
	ft_putchar_fd('\n', fd);
}

//int main(void)
//{
//	char *test = "Something to test";
//	char *test1 = "Something to test1";
//	
//	ft_putendl_fd(test, 0);	
//	ft_putendl_fd(test1, 0);	
//}