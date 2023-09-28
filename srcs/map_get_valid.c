/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:30:49 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/27 19:16:08 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	get_map(char *line, t_data *data)
{
	if (data->game_map == NULL && allocate_initial_map(data))
		return (1);
	if (data->game_map_size == data->all_file && resize_game_map(data))
		return (1);
	data->game_map[data->game_map_size] = ft_strdup(line);
	if (data->game_map[data->game_map_size] == NULL)
	{
		handle_error(ERR_MAP_ALLOCATION_FAILED);
		return (1);
	}
	data->game_map_size++;
	return (0);
}

int	is_map_valid(t_data *data)
{
	bool	visited[MAX_HEIGHT][MAX_WIDTH];

	ft_memset(visited, false, sizeof(visited));
	if (is_map_empty(data))
		return (0);
	if (!check_valid_chars(data))
		return (0);
	if (!check_player_count(data->map, data->map_height, data->map_width))
		return (0);
	if (!is_map_closed(data))
		return (0);
	if (!check_boundary_cells(visited, data->map_height, data->map_width))
		return (0);
	return (1);
}
