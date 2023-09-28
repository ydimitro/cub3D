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
	if (strstr(line, "NO") || strstr(line, "SO")
		|| strstr(line, "WE") || strstr(line, "EA"))
		parse_texture(line, data);
	else if (strstr(line, "F") || strstr(line, "C"))
		parse_color(line, data);
	else
		get_map(line, data);
	return (0);
}

int	parse_texture(char *line, t_data *data)
{
	int		i;
	char	*texture_path;
	int		len;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	texture_path = ft_strstr(line + i, "./");
	if (texture_path)
	{
		len = ft_strlen(texture_path);
		while (len > 0 && ft_isspace(texture_path[len - 1]))
			len--;
		texture_path[len] = '\0';
		if (ft_strstr(line, "NO"))
			data->north = ft_strdup(texture_path);
		else if (ft_strstr(line, "SO"))
			data->south = ft_strdup(texture_path);
		else if (ft_strstr(line, "WE"))
			data->west = ft_strdup(texture_path);
		else if (ft_strstr(line, "EA"))
			data->east = ft_strdup(texture_path);
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
