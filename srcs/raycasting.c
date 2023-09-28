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

void	set_wall_distance(t_data *data)
{
	double	offset;
	double	step;
	double	dir;
	double	map_pos;

	if (data->ray.side == 0)
	{
		offset = data->player.x;
		step = data->ray.step_x;
		dir = data->ray.dir_x;
		map_pos = data->ray.map_x;
	}
	else
	{
		offset = data->player.y;
		step = data->ray.step_y;
		dir = data->ray.dir_y;
		map_pos = data->ray.map_y;
	}
	data->ray.perp_wall_dist = (map_pos - offset + (1 - step) / 2) / dir;
}

void	cast_through_map(t_data *data)
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
		if (data->map[data->ray.map_x][data->ray.map_y] == '1')
			data->ray.hit = 1;
		if (data->ray.hit == 0)
			cast_through_map(data);
	}
}

void	set_ray_step_and_side_dist(t_data *data)
{
	if (data->ray.dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player.x - data->ray.map_x)
			* data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->player.x)
			* data->ray.delta_dist_x;
	}
	if (data->ray.dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player.y - data->ray.map_y)
			* data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->player.y)
			* data->ray.delta_dist_y;
	}
}

void	initialize_ray(t_data *data, int x)
{
	double	cam_x;

	cam_x = 2 * x / (double)data->screen_width - 1;
	data->ray.dir_x = data->player.dir + cam_x;
	data->ray.dir_y = 1.0 + cam_x;
	data->ray.map_x = (int)data->player.x;
	data->ray.map_y = (int)data->player.y;
	data->ray.delta_dist_x = fabs(1 / data->ray.dir_x);
	data->ray.delta_dist_y = fabs(1 / data->ray.dir_y);
	data->ray.hit = 0;
	set_ray_step_and_side_dist(data);
}
void	cast_single_ray(t_data *data, int x)
{
	initialize_ray(data, x);
	cast_through_map(data);
}
