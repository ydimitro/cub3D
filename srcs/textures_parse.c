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

#include "cub3d.h"

int	get_elements( char *line, t_data *data)
{
	if (ft_strstr(line, "NO") || ft_strstr(line, "SO")
		|| ft_strstr(line, "WE") || ft_strstr(line, "EA"))
		parse_texture(line, data);
	else if (ft_strstr(line, "F") || ft_strstr(line, "C"))
		parse_color(line, data);
	else if (ft_strchr(line, '1'))
		get_map(line, data);
	return (0);
}
/**
 * Parses the texture path from the given line and loads the texture data using MLX.
 * 
 * @param line The line from the configuration file containing the texture path.
 * @param data The main data structure containing game and rendering data.
 * @return Returns 0 upon successful execution.
 */
int	parse_texture(char *line, t_data *data)
{
	int		i;
	char	*texture_path;
	int		len;

	// Initialize the index to start of the line
	i = 0;

	// Skip any leading whitespace characters
	while (ft_isspace(line[i]))
		i++;

	// Find the texture path in the line (expected to start with "./")
	texture_path = ft_strstr(line + i, "./") + 2;

	// If a texture path is found
	if (texture_path)
	{
		// Calculate the length of the texture path
		len = ft_strlen(texture_path);

		// Trim any trailing whitespace from the texture path
		while (len > 0 && ft_isspace(texture_path[len - 1]))
			len--;
		texture_path[len] = '\0';

		// Allocate memory for a new texture structure
		t_texture *new_texture = malloc(sizeof(t_texture));

		// Load the texture image using MLX and store its data in the new texture structure
		printf("%s\n", texture_path);
		new_texture->img = mlx_xpm_file_to_image(data->mlx_ptr, texture_path, &new_texture->width, &new_texture->height);
		if (!new_texture->img)
			handle_error(ERR_TEXTURE_LOAD_FAILED);
		new_texture->addr = mlx_get_data_addr(new_texture->img, &new_texture->bpp, &new_texture->line_length, &new_texture->endian);

		// Determine which direction the texture corresponds to and store the texture data in the appropriate field of the data structure
		if (ft_strstr(line, "NO"))
			data->north_tex = *new_texture;
		else if (ft_strstr(line, "SO"))
			data->south_tex = *new_texture;
		else if (ft_strstr(line, "WE"))
			data->west_tex = *new_texture;
		else if (ft_strstr(line, "EA"))
			data->east_tex = *new_texture;
	}
	return (0);
}


static int	skip_chars(char *line, int i, char *chars_to_skip)
{
	while (line[i] && ft_strchr(chars_to_skip, line[i]))
		i++;
	return (i);
}

static int	parse_single_color(char *line, int *i)
{
	int	color;

	*i = skip_chars(line, *i, " \t,-");
	color = ft_atoi(line + *i);
	while (ft_isdigit(line[*i]) || line[*i] == '-')
		(*i)++;
	return (color);
}

int	parse_color(char *line, t_data *data)
{
	int	i;
	int	red;
	int	green;
	int	blue;

	i = 0;
	i = skip_chars(line, i, " \tCF");
	red = parse_single_color(line, &i);
	green = parse_single_color(line, &i);
	blue = parse_single_color(line, &i);
	if (line[0] == 'C')
	{
		data->ceiling_color[0] = red;
		data->ceiling_color[1] = green;
		data->ceiling_color[2] = blue;
	}
	else if (line[0] == 'F')
	{
		data->floor_color[0] = red;
		data->floor_color[1] = green;
		data->floor_color[2] = blue;
	}
	return (0);
}
