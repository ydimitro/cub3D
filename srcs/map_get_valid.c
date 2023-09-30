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

#include "cub3d.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void add_line_to_game_map(char *line, t_data *data)
{
    data->game_map[data->game_map_size] = ft_strdup(line);
    if (!data->game_map[data->game_map_size])
        handle_error(ERR_MAP_ALLOCATION_FAILED);
}

int	get_map(char *line, t_data *data)
{
	if (data->game_map == NULL && allocate_initial_map(data))
        allocate_initial_map(data);
    add_line_to_game_map(line, data);
	data->game_map_size++;
	return (0);
}

void set_player(t_data *data)
{
	int	i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				set_player_start(data,data->map[i][j] , i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void print2d(char **toPrint)
{
	int i = 0;

	while (toPrint[i])
	{
		write(1, toPrint[i], ft_strlen(toPrint[i]));
		write(1, "\n", 1);
		i++;
	}
}

int	is_map_valid(t_data *data)
{
	bool	visited[MAX_HEIGHT][MAX_WIDTH];

	print2d(data->map);
	write(1, "\n", 1);
	print2d(data->game_map); // segfault

	ft_memset(visited, false, sizeof(visited));
	if (is_map_empty(data))
		return (0);
	if (!check_valid_chars(data))
		return (0);
	if (!check_player_count(data->game_map))
		return (0);
	if (!is_map_closed(data))
		return (0);
	if (!check_boundary_cells(visited, data->map_height, data->map_width))
		return (0);
	set_player(data);
	return (1);
}
