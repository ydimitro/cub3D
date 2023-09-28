/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:30:49 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/27 19:16:08 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
int ft_isspace(int c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return(1);
	return(0);
}

// static int is_all_spaces(const char *line)
// {
//     for (int i = 0; line[i] != '\0'; i++) {
//         if (!ft_isspace(line[i])) {
//             return 0; // Not all spaces
//         }
//     }
//     return 1; // All spaces
// }

int	get_map(char *line, t_data *data)
{
    // Check if data->game_map is NULL and initialize it if necessary
    if (data->game_map == NULL)
	{
        // Initialize with an initial capacity (e.g., 10) // need to check with bigger maps
        // data->game_map_capacity = 10;
        data->game_map = (char **)malloc(sizeof(char *) * data->all_file);
        if (data->game_map == NULL) {
            printf("Memory allocation failed for game_map.\n");
            return 1; // Return an error code to indicate failure
        }
    }

    // Check if you need to resize the game_map array (for dynamic sizing)
    if (data->game_map_size == data->all_file) {
        // Double the capacity or use any resizing strategy you prefer
       	data->all_file *= 2;
        data->game_map = (char **)realloc(data->game_map, sizeof(char *) * data->all_file);
        if (data->game_map == NULL) {
			 printf("Memory allocation failed for game_map.\n");
            return 1; // Return an error code to indicate failure
        }
    }

    // Copy the line into the game_map
    data->game_map[data->game_map_size] = ft_strdup(line); // You can use strdup if available, or manually allocate memory and copy
    if (data->game_map[data->game_map_size] == NULL) {
		 printf("Memory allocation failed for game_map.\n");
        return 1; // Return an error code to indicate failure
    }

    data->game_map_size++;

    printf("line:%s\n", line);
    return 0;
}
