/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:30:49 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/11 17:01:58 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*check if textures exists and have the right extension
//check if textures mentioned on map
//spaces within the textures
//check for floor and sceiling colors*/


int textures_files(t_data *data)
{
 	int fd;
	
 	fd = open(texture_path, O_RDONLY);
 	if (fd == -1)
 	{
 		perror("open");
 		return (1); //texture does not exist
 	}
 	close(fd);
	return (0); //texture exists
}

int textures_info(t_data *data)
{
	int i = 0;

	while(i < data->map_height)
	{
		if(strstr(data->map[i], NO_textures != NULL))
			return (1);
		i++;
	}
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
	if(!textures_info(&data))
		return(0);
	return(1);
}
