/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:41:39 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 11:41:42 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	match(char *searched, char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	while (searched[x] != '\0' && str[i] != '\0' && searched[x] == str[i])
	{
		x++;
		i++;
	}
	if (searched[x] == '\0' && str[i] == ' ')
		return (true);
	return (false);
}

void	open_the_file(t_main *main, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exiterr(FILE_IS_NOT_THERE);
	main->file_fd = fd;
}