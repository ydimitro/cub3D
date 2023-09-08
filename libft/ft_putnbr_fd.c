/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:09:22 by tgomes-l          #+#    #+#             */
/*   Updated: 2022/12/21 13:22:27 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln = ln * -1;
	}
	if (ln >= 0 && ln <= 9)
	{
		ft_putchar_fd(ln + '0', fd);
	}
	else if (ln > 9)
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
}

//int main(void)
//{
//	ft_putnr_fd(-2147483648, 0);
//	write(1,"\n",1);
//	ft_putnr_fd(2147483647, 0);
//	write(1,"\n",1);
//	ft_putnr_fd(-2, 0);
//	write(1,"\n",1);
//	ft_putnr_fd(0, 0);
//	write(1,"\n",1);
//	ft_putnr_fd(895, 0);
//	write(1,"\n",1);
//}
//if (n == -2147483648)
	//{
	//	write(fd, "-2147483648", 11);
	//}
	//if (n < 0 && n != -2147483648)
	//{
	//	n = n * -1;
	//	write(fd, "-", 1);
	//}
	//if (n >= 0 && n <= 9)
	//{
	//	n = n + '0';
	//	write(fd, &n, 1);
	//}
	//else if (n > 9)
	//{
	//	ft_putnbr_fd(n / 10, fd);
	//	ft_putnbr_fd(n % 10,fd);
	//}