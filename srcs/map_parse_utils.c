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

int	count_players(char **game_map)
{
	int	player_count;
	int	i;
	int	j;

	player_count = 0;
	i = 0;
	while (game_map[i] && i < MAP_MAX_SIZE)
	{
		printf("%d\n", i);
		j = 0;
		while (game_map[i][j] && j < MAP_MAX_SIZE)
		{
			if (game_map[i][j] == 'N' || game_map[i][j] == 'S'
				|| game_map[i][j] == 'E' || game_map[i][j] == 'W')
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

int	allocate_initial_map(t_data *data)
{
	data->game_map = (char **)ft_calloc(1, sizeof(char *) * (data->all_file + 1));
	if (data->game_map == NULL)
	{
		handle_error(ERR_MAP_ALLOCATION_FAILED);
		return (1);
	}
	return (0);
}
