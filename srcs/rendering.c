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

#include "../includes/cub3d.h"

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return (angle);
}

void	render(t_data *data)
{
	int		x;
	float	ray_angle;
	float	slice_height;
	float	top_pixel;

	x = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (x < data->map_width)
	{
		ray_angle = normalize_angle(data->player_dir
				+ (x - data->map_width / 2) * FOV / data->map_width);
		cast_single_ray(data, x);
		slice_height = (data->tile_size / data->ray.perp_wall_dist)
			* data->DIST_TO_PROJ_PLANE;
		top_pixel = (data->map_height / 2) - (slice_height / 2);
		if (top_pixel < 0)
			return ;
		if (data->ray.hit)
			draw_wall_slice(data, x);
		x++;
	}
}

