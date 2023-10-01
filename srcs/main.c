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

/*
This function iterates over each row of the map stored in the data structure.
For each row, it retrieves the corresponding line of the map and calls
the get_elements function with this line and the data structure.
The get_elements function parses the line to extract relevant information
about the map (e.g., wall positions, player start position, etc.).
The function always returns 0.
*/
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

/*
This function opens the file specified by filename for reading.
It then reads each line of the file using the get_next_line function
and stores up to MAP_MAX_SIZE lines in the data structure.
The function also counts the number of lines read and stores this count
in data->all_file. After reading all lines, it calls file_divider
to process the map. If the file cannot be opened, it prints an error
message and returns -1. Otherwise, it returns 0.
*/
int read_and_parse_file(char *filename, t_data *data)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (-1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        if (data->all_file < MAP_MAX_SIZE)
        {
            data->map[data->all_file] = ft_strdup(line);
            data->all_file++;
        }
		free(line);
    }
    file_divider(data->all_file, data);
    close(fd);
    return (0);
}

void check_file_ending(char *filename)
{
    char	*dot;

    dot = ft_strrchr(filename, '.');
    if (dot == NULL || ft_strcmp(dot, ".cub") != 0)
    {
        handle_error(ERR_INVALID_EXT);
    }
}

void parse_file(char *filename, t_data *data)
{
    if (read_and_parse_file(filename, data) == -1)
    {
        free_mem(data);     //might cause freeing error
        handle_error(ERR_READ_FILE);
    }
}

void print_2d_array(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		write(1, map[i], ft_strlen(map[i]));
		write(1, "\n", 1);
		i++;
	}
}

/*
1. Check - one arg? .cub?
2. initializing of data structure
3. Call read_and_parse_file to read and process the map file, -1 (error, free)
4. Set screen width and height
5. MLX init, create window, key press event handler, MLX loop during play
*/
int	main(int argc, char **argv)
{
    t_data	*data;

    if (argc != 2)
    {
        handle_error(ERR_INVALID_ARGC);
    }
    check_file_ending(argv[1]);
    data = create_data();
    data_init(data);
    parse_file(argv[1], data);
	printf("4x:%f | y: %f\n", data->player.x, data->player.y);
    is_map_valid(data);
    //call co rendering 
    mlx_hook(data->win_ptr, 2, 0, &key_press, data);


  
    // Enter the MLX loop to keep the window open
	printf("5x:%f | y: %f\n", data->player.x, data->player.y);
	printf("before\n");
    mlx_loop(data->mlx_ptr);
    
    return (0);
}
