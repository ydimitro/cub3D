/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:10:47 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 08:10:47 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_wall_slice(t_data *data, int x)
{
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = (data->ray.map_x - data->player.x + (1 - data->ray.step_x) / 2) / data->ray.ray_dir_x;
	else
		data->ray.perp_wall_dist = (data->ray.map_y - data->player.y + (1 - data->ray.step_y) / 2) / data->ray.ray_dir_y;

	int line_height = (int)(data->screen_height / data->ray.perp_wall_dist);
	int draw_start = -line_height / 2 + data->screen_height / 2;
	int draw_end = line_height / 2 + data->screen_height / 2;

	// Color the wall slice. For now, simple color differentiation based on direction
	int color;
	if (data->ray.side == 0)
		color = (data->ray.step_x == 1) ? 0xFF0000 : 0x00FF00;
	else
		color = (data->ray.step_y == 1) ? 0x0000FF : 0xFFFF00;

	while (draw_start <= draw_end)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, draw_start, color);
		draw_start++;
	}
	draw_textured_walls(&data, x);
}

void cast_through_map(t_data *data)
{
	if (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}

		if (data->map[data->ray.map_x][data->ray.map_y] == '1')  // assuming 1 indicates wall
			data->ray.hit = 1;

		if (data->ray.hit == 0)
			cast_through_map(data);
	}
}


void cast_single_ray(t_data *data, int x)
{
	// Calculate ray direction
	double cam_x = 2 * x / (double)data->screen_width - 1; 
	data->ray.ray_dir_x = data->player.direction + cam_x;
	data->ray.ray_dir_y = 1.0 + cam_x;

	// Initial map position
	data->ray.map_x = (int)data->player.x;
	data->ray.map_y = (int)data->player.y;

	// Calculate distance ray has to travel to next x or y-side of grid square
	data->ray.delta_dist_x = fabs(1 / data->ray.ray_dir_x);
	data->ray.delta_dist_y = fabs(1 / data->ray.ray_dir_y);
	data->ray.hit = 0;

	// Calculate step direction and initial side distance
	if (data->ray.ray_dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player.x - data->ray.map_x) * data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->player.x) * data->ray.delta_dist_x;
	}
	if (data->ray.ray_dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player.y - data->ray.map_y) * data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->player.y) * data->ray.delta_dist_y;
	}

	// find where the ray hits a wall (recursive)
	cast_through_map(data);
}


//render