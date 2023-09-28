/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 03:33:11 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/27 18:42:45 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int file_divider(int row, t_data *data)
{
	int i = 0;
	char *line;
	while (i < row)
	{
		line = data->map[i];
		get_elements(line, data);

		i++;
	}
	return(0);
}

int manage_fd(char *filename, t_data *data)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	char *line;
	int row = 0;
	while ((line = get_next_line(fd)) != NULL) 
	{
		if (row < MAP_MAX_SIZE)
		{
			data->map[row] = ft_strdup(line);
			row++;
		}
		data->all_file = row;
		free(line);
	}
	file_divider(row, data);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dot;
	t_data	data;
	
	if (argc != 2)
	{
		handle_error(ERR_INVALID_ARGC);
		return (1);
	}
	else	
	{	
		dot = ft_strrchr(argv[1], '.');
		if (dot == NULL || ft_strcmp(dot, ".cub") != 0)
		{
			handle_error(ERR_INVALID_EXT);
			return (1);
		}
		data_init(&data);
		if (manage_fd(argv[1], &data) == -1)
		{
			handle_error(ERR_READ_FILE);
			free_mem(&data);
			return (1);
		}
		free_mem(&data);
	}
	data.screen_width = MAX_WIDTH;
	data.screen_height = MAX_HEIGHT;
	// Initializing MLX and creating a window
	data.mlx_ptr = mlx_init();
	printf("width: %d\nheight:%d\n", data.screen_width, data.screen_height);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.screen_width, data.screen_height, "Cub3D");
	mlx_hook(data.win_ptr, 2, 0, &key_press, &data);
	// Enter the MLX loop to keep the window open
	mlx_loop(data.mlx_ptr);
	return (0);
}
