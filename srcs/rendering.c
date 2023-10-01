/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:53:56 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 23:53:56 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return (angle);
}

t_texture *ray_direction(t_data *data)
{
	int x;
	int y;

	x = data->ray.map_x - data->player.x;
	y = data->ray.map_x - data->player.y;

	//cover 4 condtion 
	if (x > 0 && y > 0)
		return (&data->north_tex);
	else if (x < 0 && y < 0)
		return (&data->south_tex);
	else if (x < 0 && y > 0)
		return (&data->east_tex);
	else
		return (&data->west_tex);

}

void	set_texture(t_data *data, t_texture **tex)
{
	//vertical wall
	if (data->ray.side == 0)
	{
		if (data->ray.step_x == 1) //if moving right, south tex, north otherwise
			*tex = &data->south_tex;
		else
			*tex = &data->north_tex;
	}
	else // != 0 horizontal wall, same logic
	{
		if (data->ray.step_y == 1)
			*tex = &data->east_tex;
		else
			*tex = &data->west_tex;
	}
}

t_texture *get_hit_texture(t_data *data)
{
	t_texture *tex;

	set_texture(data, &tex);
	return tex;
}

bool ray_casting(t_data *data, int pixel)
{
	float	ray_angle;
	float	slice_height;
	float	top_pixel;

	ray_angle = normalize_angle(data->player_dir
				+ (pixel - data->map_width / 2) * FOV / data->map_width);
	cast_single_ray(data, pixel);
	slice_height = (data->tile_size / data->ray.perp_wall_dist)
		* data->DIST_TO_PROJ_PLANE;
	top_pixel = (data->map_height / 2) - (slice_height / 2);
	if (top_pixel < 0)
		return false;
	if (data->ray.hit)
		return true;
	return false;
}



void	render(t_data *data)
{
	int		x;
	t_texture *texture;

	x = 0;
	while (x < data->map_width)
	{
		if (ray_casting(data, x))
		{
			texture = get_hit_texture(data);
			draw_wall_slice(data, x);
			
			// call drawing function here
		}
		x++;
	}
}


