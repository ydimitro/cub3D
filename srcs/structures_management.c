/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:21:34 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/10 18:21:44 by tgomes-l         ###   ########.fr       */
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
	return(0);
}

void data_initiziated(t_data *data)
{
	data->map = (char **)malloc(sizeof(char *) * MAP_MAX_SIZE);
	data->map_width = 0;
	data->map_height = 0;
}
