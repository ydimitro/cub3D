/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:27:53 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/27 19:09:21 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void data_init(t_data *data)
{
	int i; 
	data->map = (char **)malloc(sizeof(char *) * MAP_MAX_SIZE);
	if (!data->map)
        return;
	i = 0;
    while (i < MAP_MAX_SIZE) 
    {
        data->map[i] = 0;
        i++;
    }
	data->map_width = 0;
	data->map_height = 0;
	data->game_map = 0;
	data->game_map_size = 0;
	data->game_map_capacity = 0;
	data->player.x = 2.0;  // Starting position
	data->player.y = 2.0;  // Starting position
	data->player.direction = 3.14159 / 2;  // Facing north
	data->player.speed = 0.1;
	data->player.turn_speed = 0.05;  // radians per key press
}

void load_texture(t_data *data, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &tex->width, &tex->height);
	if (!tex->img)
	{
		ft_putstr("Error loading texture.\n");
		exit(1); // Handle this more gracefully in your real code
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length, &tex->endian);

	load_texture(data, &data->north_tex, "path_to_north_texture.xpm");
	load_texture(data, &data->south_tex, "path_to_south_texture.xpm");
	load_texture(data, &data->west_tex, "path_to_west_texture.xpm");
	load_texture(data, &data->east_tex, "path_to_east_texture.xpm");

}

