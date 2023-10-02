/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:43:39 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 18:23:32 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_colision_a(t_wall *height, int check_wall_colision)
{
	t_collision_data	data;

	data.center1 = 0;
	data.center2 = 0;
	data.corner1 = 0;
	data.corner2 = 0;
	check_wall_colision = check_wall(height, height->p_m[4], height->p_m[5]);
	if (check_center_and_corners(height, &data))
		return (1);
	return (check_wall_colision);
}

int	wall_colision_s(t_wall *height, int check_wall_colision)
{
	t_collision_data	data;

	data.center1 = 0;
	data.center2 = 0;
	data.corner1 = 0;
	data.corner2 = 0;
	check_wall_colision = check_wall(height, height->p_m[6], height->p_m[7]);
	if (check_center_and_corners(height, &data))
		return (1);
	return (check_wall_colision);
}

int	wall_colision_w(t_wall *height, int check_wall_colision)
{
	t_collision_data	data;

	data.center1 = 0;
	data.center2 = 0;
	data.corner1 = 0;
	data.corner2 = 0;
	check_wall_colision = check_wall(height, height->p_m[0], height->p_m[1]);
	data.center1 = check_wall(height, height->p_m[2], height->p_m[3]);
	data.center2 = check_wall(height, height->p_m[4], height->p_m[5]);
	data.corner1 = check_wall(height, height->p_c[2], height->p_c[3]);
	data.corner2 = check_wall(height, height->p_c[0], height->p_c[1]);
	if ((data.center1 != 0 || data.corner1 != 0) && \
			(data.center2 != 0 || data.corner2 != 0))
	{
		if ((height->pos_cur_x - TILE) / (TILE) != \
			(height->p_m[0] - TILE) / (TILE))
			return (1);
		if ((height->pos_cur_y - TILE) / (TILE) != \
			(height->p_m[1] - TILE) / (TILE))
			return (1);
	}
	return (check_wall_colision);
}

int	wall_colision_d(t_wall *height, int check_wall_colision)
{
	t_collision_data	data;

	data.center1 = 0;
	data.center2 = 0;
	data.corner1 = 0;
	data.corner2 = 0;
	check_wall_colision = check_wall(height, height->p_m[2], height->p_m[3]);
	data.center1 = check_wall(height, height->p_m[0], height->p_m[1]);
	data.center2 = check_wall(height, height->p_m[6], height->p_m[7]);
	data.corner1 = check_wall(height, height->p_c[2], height->p_c[3]);
	data.corner2 = check_wall(height, height->p_m[6], height->p_m[7]);
	if ((data.center1 != 0 || data.corner1 != 0) && \
		(data.center2 != 0 || data.corner2 != 0))
	{
		if ((height->pos_cur_x - TILE) / (TILE) != \
			(height->p_m[2] - TILE) / (TILE))
			return (1);
		if ((height->pos_cur_y - TILE) / (TILE) != \
			(height->p_m[3] - TILE) / (TILE))
			return (1);
	}
	return (check_wall_colision);
}

int	wall_colision_check(t_wall *height, int keycode)
{
	int	check_wall_colision;

	check_wall_colision = 0;
	if (keycode == W_KEY)
		return (wall_colision_w(height, check_wall_colision));
	else if (keycode == S_KEY)
		return (wall_colision_s(height, check_wall_colision));
	else if (keycode == A_KEY)
		return (wall_colision_a(height, check_wall_colision));
	else if (keycode == D_KEY)
		return (wall_colision_d(height, check_wall_colision));
	return (0);
}
