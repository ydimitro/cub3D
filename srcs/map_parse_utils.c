/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:30:28 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/27 04:07:40 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_char(char c)
{
	if (ft_isspace(c) || c == '0' || c == '1' || c == 'N' || \
		c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int	count_players(char **map, int height, int width)
{
	int	player_count;
	int	i;
	int	j;

	player_count = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				player_count++;
			}
			j++;
		}
		i++;
	}
	return (player_count);
}

void	dfs(int row, int col, t_data *data,
	bool visited[data->map_height][data->map_width])
{
	if (row < 0 || row >= data->map_height || col < 0
		|| col >= data->map_width || visited[row][col]
		|| data->map[row][col] == '0')
		return ;
	visited[row][col] = true;
	dfs(row + 1, col, data, visited);
	dfs(row - 1, col, data, visited);
	dfs(row, col + 1, data, visited);
	dfs(row, col - 1, data, visited);
}

int	resize_game_map(t_data *data)
{
	char	**temp;

	data->all_file *= 2;
	temp = (char **)realloc(data->game_map, sizeof(char *) * data->all_file);
	if (!temp)
	{
		handle_error(ERR_MAP_ALLOCATION_FAILED);
		return (1);
	}
	data->game_map = temp;
	return (0);
}

int	allocate_initial_map(t_data *data)
{
	data->game_map = (char **)malloc(sizeof(char *) * data->all_file);
	if (data->game_map == NULL)
	{
		handle_error(ERR_MAP_ALLOCATION_FAILED);
		return (1);
	}
	return (0);
}
