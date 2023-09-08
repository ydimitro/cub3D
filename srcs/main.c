/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:45:37 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/08 18:55:22 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int manage_fd(char *filename)
{
	int fd;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror("open");
	char *line;
	while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dot;
	
	dot = ft_strrchr(argv[1], '.');
	if (argc != 2)
	{
		ft_putstr("Please execute ./cub_3d with a map as argument, example: ./cub_3d maps/cub_3d\n");
		return (1);
	}
	else	
	{	
		if (dot == NULL || ft_strcmp(dot, ".cub") != 0)
		{
			ft_putstr("Invalid file extension. Only .cub files are supported.\n");
			return (1);
		}		
		if (manage_fd(argv[1]) == -1)
		{
			ft_putstr("An error occurred while reading the file.\n");
			return (1);
		}
	}
	return (0);
}