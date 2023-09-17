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

int manage_fd(char *filename, t_data *data) {
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    char *line;
    int row = 0;
    int found_1111 = 0; // Flag to indicate if "1111" has been found
	int found_NO = 0;   // Flags for other elements
    int found_SO = 0;
    int found_WE = 0;
    int found_EA = 0;
    while ((line = get_next_line(fd)) != NULL) {
        if (row < MAP_MAX_SIZE) {
            if (found_1111) {
                // Allocate memory for the row and copy the line
                data->map[row] = ft_strdup(line);
                row++;
            } else if (ft_strstr(line, "1111")) {
                found_1111 = 1; // Set the flag to indicate "1111" was found
            } else if (ft_strstr(line, "NO")) {
                data->north = ft_strdup(line); // Store in data->north
                found_NO = 1;
            } else if (ft_strstr(line, "SO")) {
                data->south = ft_strdup(line); // Store in data->south
                found_SO = 1;
            } else if (ft_strstr(line, "WE")) {
                data->west = ft_strdup(line);  // Store in data->west
                found_WE = 1;
            } else if (ft_strstr(line, "EA")) {
                data->east = ft_strdup(line);  // Store in data->east
                found_EA = 1;
            }

        }
        // Print the map to test
        free(line);
    }

    // tests
	printf("%s", data->east);
	printf("%s", data->west);
	int i = 0;
    while (i < row)
	{
        if (data->map[i]) {
            printf("%s", data->map[i]);
        }
		i++;
    }

	if (!(found_1111 && found_NO && found_SO && found_WE && found_EA)) {
    	ft_putstr("Error: Missing required elements.\n");
    return 1;
    }
    close(fd);
    data->map_height = row;
    return 0;
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
		data_initiziated(&data, MAP_MAX_SIZE);
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


