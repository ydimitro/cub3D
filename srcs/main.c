/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   main.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: tgomes-l <tgomes-l@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/09/08 11:45:37 by tgomes-l	  #+#	#+#	 */
/*   Updated: 2023/09/19 04:06:21 by tgomes-l	 ###   ########.fr	   */
/*	*/
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
		//get_map(line, data);
		i++;
	}
	return(0);
}

int manage_fd(char *filename, t_data *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
	perror("open");
	return 1;
	}
	char *line;
	int row = 0;
	while ((line = get_next_line(fd)) != NULL) 
	{
		if (row < MAP_MAX_SIZE) {
				data->map[row] = ft_strdup(line);
				row++;
		}
		data->all_file = row;
		free(line);
	}
	file_divider(row, data);
	close(fd);
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
	printf("%s\n", data.north);//testing
   	printf("%s\n", data.south);//testing
    printf("%s\n", data.east);//testing
    printf("%s\n", data.west);//testing
	printf("%s\n", data.west);//testing
	printf("Ceiling Color: R=%d, G=%d, B=%d\n", data.ceiling_color[0], data.ceiling_color[1], data.ceiling_color[2]);
    printf("Floor Color: R=%d, G=%d, B=%d\n", data.floor_color[0], data.floor_color[1], data.floor_color[2]);
	free_mem(&data);
	}
	return (0);
}


