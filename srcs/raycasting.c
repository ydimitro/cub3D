/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:42:21 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 17:23:48 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
1. Calculate the angle of the ray.
2. Calculate the quadrant of the ray.
3. Calculate the real angle of the ray.
4. Count the vertical and horizontal scaling.
5. Do the first vertical and horizontal calculations.
6. Check if the first vertical and horizontal hit the wall.
7. If not, count the next vertical and horizontal calculations.
8. If yes, calculate the distance to the wall.
9. Draw the ray on the screen.
10. Repeat steps 5-9 until the last ray is drawn.
11. Go back to step 1 and repeat until all the rays are drawn
 */

#include "cub3d.h"

void	rest_horizontal(t_wall *height, int start_tile_pos_y, int step)
{
	height->current_hor_len = TILE / sin(height->real_angle * RADIAN);
	if (height->quadrant == 4 || height->quadrant == 3)
		height->current_hor_y = start_tile_pos_y + (TILE) + ((TILE) * step);
	else
		height->current_hor_y = start_tile_pos_y - ((TILE) * step);
	if (height->quadrant == 3 || height->quadrant == 2)
		height->current_hor_x -= height->horizontal_x_scaling;
	else
		height->current_hor_x += height->horizontal_x_scaling;
}

void	rest_vertical(t_wall *height, int start_tile_pos_x, int step)
{
	height->current_ver_len = TILE / cos(height->real_angle * RADIAN);
	height->current_ver_x = start_tile_pos_x + (TILE) * step + (TILE);
	if (height->quadrant == 3 || height->quadrant == 4)
		height->current_ver_y += height->vertical_y_scaling;
	else
		height->current_ver_y -= height->vertical_y_scaling;
	if (height->quadrant == 3 || height->quadrant == 2)
		height->current_ver_x = start_tile_pos_x - (TILE) * step;
}

void	raycasting(t_wall *height, int start_tile_pos_x, int start_tile_pos_y)
{
	int		step;
	int		hor_hit;
	int		ver_hit;

	step = 1;
	ver_hit = 0;
	hor_hit = 0;
	first_horizontal(height, start_tile_pos_x, start_tile_pos_y);
	first_vertical(height, start_tile_pos_x, start_tile_pos_y);
	hor_hit = check_horizontal_wall(height);
	ver_hit = check_vertical_wall(height);
	while (hor_hit == 0)
	{
		rest_horizontal(height, start_tile_pos_y, step++);
		hor_hit = check_horizontal_wall(height);
	}
	step = 1;
	while (ver_hit == 0)
	{
		rest_vertical(height, start_tile_pos_x, step++);
		ver_hit = check_vertical_wall(height);
	}
	if (ver_hit != 0 && hor_hit != 0)
		height->shortest_dist_to_wall = \
			calculate_dist_draw(height, hor_hit, ver_hit);
}

void	draw_2d_rays(t_wall *height)
{
	int		i;
	double	fov;
	int		start_tile_pos_x;
	int		start_tile_pos_y;

	i = 0;
	fov = -30;
	height->angle -= 30;
	height->current_tile_pos_y = (height->pos_cur_y - TILE) / TILE;
	height->current_tile_pos_x = (height->pos_cur_x - TILE) / TILE;
	start_tile_pos_x = (TILE + (height->current_tile_pos_x * TILE));
	start_tile_pos_y = (TILE + (height->current_tile_pos_y * TILE));
	while (i < S_WIDTH)
	{
		decide_quadrant(height);
		height->real_angle = fabs((double)90 - remainder(height->angle + \
									(double)height->p_offset, (double)180));
		count_vertical_scaling(height);
		count_horizontal_scaling(height);
		raycasting(height, start_tile_pos_x, start_tile_pos_y);
		draw_3d(height, i++, fov);
		height->angle += height->one_colum_increase;
		fov += height->one_colum_increase;
	}
	height->angle -= 30;
}
