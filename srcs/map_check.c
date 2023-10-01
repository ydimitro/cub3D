/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:00:53 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 08:00:53 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_empty(t_data *data)
{
	if (data->map[0] == 0)
	{
		handle_error(ERR_EMPTY_MAP);
		return (1);
	}
	return (0);
}

int	check_valid_chars(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (!is_valid_char(data->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player_count(char **map)
{
	int	player_count;

	player_count = count_players(map);
	if (player_count != 1)
	{
		handle_error(ERR_PLAYER_NR);
		return (0);
	}
	return (1);
}

bool	is_map_closed(t_data *data)
{
	int		i;
	int		j;
	bool	visited[MAX_HEIGHT][MAX_WIDTH];

	i = 0;
	ft_memset(visited, false, sizeof(visited));
	dfs((int)data->player.x, (int)data->player.y, data, visited);
	while (i < data->map_width)
	{
		if (!visited[0][i] || !visited[data->map_height - 1][i])
			return (false);
		i++;
	}
	j = 0;
	while (j < data->map_height)
	{
		if (!visited[j][0] || !visited[j][data->map_width - 1])
			return (false);
		j++;
	}
	return (true);
}

int	check_boundary_cells(bool visited[][MAX_WIDTH], int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		if (!visited[0][i] || !visited[height - 1][i])
			return (0);
		i++;
	}
	j = 0;
	while (j < height)
	{
		if (!visited[j][0] || !visited[j][width - 1])
			return (0);
		j++;
	}
	return (1);
}
