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

void	data_init(t_data *data)
{
	int	i;
	
	data->DIST_TO_PROJ_PLANE = (SCREEN_WIDTH / 2) / tan(FOV / 2);
	data->map = (char **)malloc(sizeof(char *) * MAP_MAX_SIZE);
	if (!data->map)
		handle_error(ERR_MAP_ALLOCATION_FAILED);
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
	data->player.x = 2.0;
	data->player.y = 2.0;
	data->player.dir = 3.14159 / 2;
	data->player.speed = 0.1;
	data->player.turn_speed = 0.05;
}
static void load_texture(t_data *data, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(data->mlx_ptr,
			path, &tex->width, &tex->height);
	if (!tex->img)
		handle_error(ERR_TEXTURE_LOAD_FAILED);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_length, &tex->endian);
}

void	load_all_textures(t_data *data)
{
	load_texture(data, &data->north_tex, "path_to_north_texture.xpm");
	load_texture(data, &data->south_tex, "path_to_south_texture.xpm");
	load_texture(data, &data->west_tex, "path_to_west_texture.xpm");
	load_texture(data, &data->east_tex, "path_to_east_texture.xpm");
}

