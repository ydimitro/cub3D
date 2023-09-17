/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:21:34 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/17 19:51:09 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int free_mem(t_data *data)
{
	int i = 0;
	while(i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
  free(data->map);
  free(data->north);
  free(data->south);
  free(data->west);
  free(data->east);
	return(0);
}

void data_initiziated(t_data *data, int map_size)
{
    int i;
    data->map = (char **)malloc(sizeof(char *) * map_size);
    if (!data->map)
        return;
    // Initialize all map pointers to NULL
    i = 0;
    while (i < map_size) 
    {
        data->map[i] = 0;
        i++;
    }
    // data->map_width = 0;
    // data->map_height = 0;
    // data->north = NULL;
    // data->south = NULL;
    // data->west = NULL;
    // data->east = NULL;
    // data->ceiling_r = 0;
    // data->ceiling_g = 0;
    // data->ceiling_b = 0;
    // data->floor_r = 0;
    // data->floor_g = 0;
    // data->floor_b = 0;
}
