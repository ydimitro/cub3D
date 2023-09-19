/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:45:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/19 04:00:44 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to parse texture-and-color-related lines

int get_elements(char *line, t_data *data)
{
	if(strstr(line, "NO") || strstr(line, "SO") || strstr(line, "WE") || strstr(line, "EA"))
		parse_texture(line, data);
	else if(strstr(line, "EA"))
		parse_texture(line, data);
	//else if(strstr(line, "F") || strstr(line, "C"))
	// 	parse_color(line, data);
	
	return(0);
}

int get_map(char *line, t_data *data)
{
	int map_start = 0;
	
	if(ft_isprint(line))
		map_start = line;
	while(map_start < data->all_file)
	{

	}
	
}

int	parse_texture(char *line, t_data *data)
{
	int i = 0;
	char *texture_path;
	
	while(ft_isspace(line[i]))
		i++;
	if (!line[i])
        return 0;
	texture_path = &line[i];
	if (strstr(line, "NO")) {
        data->north = ft_strdup(texture_path);
    } else if (strstr(line, "SO")) {
        data->south = ft_strdup(texture_path);
    } else if (strstr(line, "WE")) {
        data->west = ft_strdup(texture_path);
    } else if (strstr(line, "EA")) {
        data->east = ft_strdup(texture_path);
	}
	return(0);
}