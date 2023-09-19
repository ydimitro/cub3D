/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:30:49 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/19 04:41:49 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int ft_isspace(int c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return(1);
	return(0);
}

static int	is_valid_char(char c)
{
	if (ft_isspace(c) || c == '0' || c == '1' || c == 'N' || \
		c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int	is_map_valid(t_data *data)
{
	int	i;
	i = 0;
	if (data->map[i] == 0)
	{
		ft_putstr("The map is empty\n");
		return (0);
	}
	while (data->map[i][i] != 0)
	{
		if (!is_valid_char(data->map[i][i]))
			return (0);
		i++;
	}
	// if (!is_map_closed(data))
	// 	return (0);
	return(1);
}

int get_map(char *line, t_data *data)
{
	int map_started = 0; // keep track of whether the map has started
	
	// Skip leading whitespace
	int i = 0;
	while (line[i] && ft_isspace(line[i]))
	    i++;
	
	// Check if the line is empty
	if (!line[i])
	    return (0);
	
	// If the map has not started yet, set map_started flag
	if (!map_started)
	    map_started = 1;
	
	// Allocate memory for the map row and copy the line into it
	data->map[data->map_height] = ft_strdup(line);
	printf("Stored map line: %s\n", data->map[data->map_height]);
	
	// Update the map height
	data->map_height++;
	
	// Update the map width if needed
	int line_length = ft_strlen(line);
	if (line_length > data->map_width)
	    data->map_width = line_length;
	
	return (0);
	
}