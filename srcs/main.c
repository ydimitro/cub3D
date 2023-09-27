/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 03:33:11 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/27 03:33:30 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int file_divider(int row, t_data *data)
{
	int i = 0;
	char *line;
	while (i < row)
	{
		line = data->map[i];
		get_elements(line, data);
		//get_map(line, data);
		i++;
	}
	return(0);
}

int manage_fd(char *filename, t_data *data)
{
	int fd;
	int player_start_found = 0; // Flag to track if player's starting position is found.

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
		printf("%s", line);
		if (row < MAP_MAX_SIZE)
		{
			data->map[row] = ft_strdup(line);
			row++;
			//Adjust the map parsing routine: Player starting direction
			int col = 0;
			while (line[col])
			{
				if (strchr("NSEW", line[col])) {
					int err = set_player_start(data, line[col], col, row, &player_start_found);
					if (err != SUCCESS) {
						handle_error(err);
						free(line);
						return (-1);  // Return an error code to the caller.
					}
				}
				col++;
			}
		}
		data->all_file = row;
		free(line);
	}
	file_divider(row, data);
	close(fd);
	data->map_height = row;

	// Calculate map_width (assuming all rows have the same length)
	if (data->map_height > 0)
		data->map_width = strlen(data->map[0]);
	
	if (!player_start_found)
	{
		handle_error(ERR_NO_START);
		return (-1);  // Return an error code to the caller.
	}
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
		data_init(&data);
		if (manage_fd(argv[1], &data) == -1)
		{
			ft_putstr("An error occurred while reading the file.\n");
			free_mem(&data);
			return (1);
		}
		free_mem(&data);
	}

	// Initializing MLX and creating a window
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.screen_width, data.screen_height, "Cub3D");

	// Draw a rectangle to test drawing capabilities
	//draw_rectangle(&data, 200, 250, 400, 100, 0x00FF00);

	mlx_hook(data.win_ptr, 2, 0, &key_press, &data);

	// Enter the MLX loop to keep the window open
	mlx_loop(data.mlx_ptr);

	return (0);
}
