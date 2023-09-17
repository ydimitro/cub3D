/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:45:37 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/17 19:53:41 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int manage_fd(char *filename, t_data *data)
{
	int fd;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	char *line;
	int row = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		// printf("%s", line);
		if (row < MAP_MAX_SIZE)
		{
			printf("%d", row);
			// //skipspaces
			// ft_skipspaces(line)
			// if(ft_strstr(line, "NO") == 0)
			// 	//check for NO texture
			// else if(ft_strstr(line, "SO") == 0)
			// 	//check for texture
			// else if(ft_strstr(line, "WE") == 0)
			// 	//check for texture
			// else if(ft_strstr(line, "EA") == 0)
			// 	//check for texture
			// printf("%s", line);
			// //check colors
			// if(ft_strstr(data->map[row], "1111"))//where map starts
				data->map[row] = ft_strdup(line);
			row++;
		}
		free(line);
	}
	close(fd);
	data->map_height = row;
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dot;
	t_data	data;
	
	if (argc != 2)
	{
		ft_putstr("Please execute like example: ./cub_3d maps/cub_3d\n");
		return (1);
	}
	else	
	{	
		dot = ft_strrchr(argv[1], '.');
		if (dot == NULL || ft_strcmp(dot, ".cub") != 0)
		{
			ft_putstr("Invalid file extension. Only .cub files are supported.\n");
			return (1);
		}
		data_initiziated(&data);
		if (manage_fd(argv[1], &data) == -1)
		{
			ft_putstr("An error occurred while reading the file.\n");
			free_mem(&data);
			return (1);
		}
		free_mem(&data);
	}
	return (0);
}


