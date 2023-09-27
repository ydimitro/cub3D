/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:45:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/27 18:44:25 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Function to parse texture-and-color-related lines

int get_elements( char *line, t_data *data)
{
	if(strstr(line, "NO") || strstr(line, "SO") || strstr(line, "WE") || strstr(line, "EA"))
		parse_texture(line, data);
	// else if(strstr(line, "EA"))
	//  	parse_texture(line, data);
	else if(strstr(line, "F") || strstr(line, "C"))
	    parse_color(line, data);
	else
		get_map(line, data);
	return (0);
}

int	parse_texture(char *line, t_data *data)
{
    int i = 0;
        
    // Skip leading spaces
    while (ft_isspace(line[i]))
    {
        i++;
    }
        
    // Find the texture path
    char *texture_path = ft_strstr(line + i, "./");
        
    if (texture_path) {
        // Remove trailing spaces (if any)
        int len = ft_strlen(texture_path);
        while (len > 0 && ft_isspace(texture_path[len - 1])) {
            len--;
        }
        texture_path[len] = '\0'; // Null-terminate the path
        
        if (ft_strstr(line, "NO")) {
            data->north = ft_strdup(texture_path);
        } else if (ft_strstr(line, "SO")) {
            data->south = ft_strdup(texture_path);
        } else if (ft_strstr(line, "WE")) {
            data->west = ft_strdup(texture_path);
        } else if (ft_strstr(line, "EA")) {
            data->east = ft_strdup(texture_path);
        }
    }
    return 0;
}

int	parse_color(char *line, t_data *data)
{
	int i = 0;
	int red, green, blue;

	while (ft_isspace(line[i]))
		i++;

	// Skip the 'C' or 'F' character
	if (line[i] == 'C' || line[i] == 'F')
		i++;

	// Skip spaces until the first digit or '-'
	while (ft_isspace(line[i]) || line[i] == '-')
		i++;

	// Parse the red component
	red = ft_atoi(line + i);
	while (ft_isdigit(line[i]) || line[i] == '-')
		i++;

	// Skip spaces and ','
	while (ft_isspace(line[i]) || line[i] == ',')
		i++;

	// Parse the green component
	green = ft_atoi(line + i);
	while (ft_isdigit(line[i]) || line[i] == '-')
		i++;

	// Skip spaces and ','
	while (ft_isspace(line[i]) || line[i] == ',')
		i++;

	// Parse the blue component
	blue = ft_atoi(line + i);

	// Store the RGB values in the data structure
	if (line[0] == 'C') {
		data->ceiling_color[0] = red;
		data->ceiling_color[1] = green;
		data->ceiling_color[2] = blue;
	} else if (line[0] == 'F') {
		data->floor_color[0] = red;
		data->floor_color[1] = green;
		data->floor_color[2] = blue;
	}
	return (0);
}
