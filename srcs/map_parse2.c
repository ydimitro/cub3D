/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:30:28 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/27 04:07:40 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_char(char c)
{
	if (ft_isspace(c) || c == '0' || c == '1' || c == 'N' || \
		c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

static int	one_player(char c)
{
   int	player_count = 0; // Static variable to keep track of player count
    
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
        player_count++; // Increment the player count when a player character is encountered
        if (player_count > 1)
            return (0); // More than one player character found
    }
    
    return (1); // Only one player character found or none
}

// Function to perform depth-first search (DFS)
static void dfs(char **map, int row, int col, int map_width, int map_height, bool visited[map_height][map_width]) {
    // Check boundaries and if the cell is already visited
    if (row < 0 || row >= map_height || col < 0 || col >= map_width || visited[row][col] || map[row][col] == '0') {
        return;
    }

    // Mark the cell as visited
    visited[row][col] = true;

    // Perform DFS in all adjacent cells
    dfs(map, row + 1, col, map_width, map_height, visited); // Down
    dfs(map, row - 1, col, map_width, map_height, visited); // Up
    dfs(map, row, col + 1, map_width, map_height, visited); // Right
    dfs(map, row, col - 1, map_width, map_height, visited); // Left
}

static bool is_map_closed(char **map, int player_row, int player_col, int map_width, int map_height)
{
    bool visited[map_height][map_width];
    ft_memset(visited, false, sizeof(visited));

    // Perform DFS starting from the player's position
    dfs(map, player_row, player_col, map_width, map_height, visited);

    // Check if all boundary cells are visited
    int i = 0;
    while( i < map_width)
    {
        if (!visited[0][i] || !visited[map_height - 1][i])
            return false; // Top or bottom boundary not visited
        i++;
    }
    int j = 0;
    while ( j < map_height)
    {
        if (!visited[j][0] || !visited[j][map_width - 1])
            return false; // Left or right boundary not visited
        j++;
    }

    return true; // Map is closed
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
        if (!one_player(data->map[i][i]))
			return (0);
		i++;
	}
	if (&is_map_closed == false)
	    return (0);
	return(1);
}