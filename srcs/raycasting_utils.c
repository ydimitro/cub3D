/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:42:11 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 12:32:08 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	first_horizontal(t_wall *height, int start_tile_pos_x, int start_tile_pos_y)
{
	double	a;
	int		offsetx;
	int		offsety;

	offsetx = height->pos_cur_x - start_tile_pos_x;
	if (height->quadrant == 4 || height->quadrant == 3)
		offsety = start_tile_pos_y + (TILE) - height->pos_cur_y;
	else
		offsety = height->pos_cur_y - start_tile_pos_y;
	if (fabs(remainder(height->angle + height->p_offset, 180)) == 90)
		a = 10000000;
	else
		a = fabs(offsety / tan(height->real_angle * RADIAN));
	height->current_hor_len = a / cos(height->real_angle * RADIAN);
	height->current_hor_x = start_tile_pos_x + offsetx + a;
	if (height->quadrant == 3 || height->quadrant == 4)
		height->current_hor_y = height->pos_cur_y + offsety;
	else
		height->current_hor_y = start_tile_pos_y;
	if (height->quadrant == 3 || height->quadrant == 2)
		height->current_hor_x = start_tile_pos_x + offsetx - a;
}

void	first_vertical(t_wall *height, int start_tile_pos_x, int start_tile_pos_y)
{
	double	a;
	double	b;
	int		offsety;

	offsety = height->pos_cur_y - start_tile_pos_y;
	if (height->quadrant == 1 || height->quadrant == 4)
		a = start_tile_pos_x + (TILE) - height->pos_cur_x;
	else
		a = height->pos_cur_x - start_tile_pos_x;
	if (fabs(remainder(height->angle + height->p_offset, 180)) == 0)
		b = 10000000;
	else
		b = fabs(a * tan(height->real_angle * RADIAN));
	height->current_ver_len = b / sin(height->real_angle * RADIAN);
	height->current_ver_x = start_tile_pos_x;
	height->current_ver_y = start_tile_pos_y + offsety - b;
	if (height->quadrant == 1 || height->quadrant == 4)
		height->current_ver_x = start_tile_pos_x + (TILE);
	if (height->quadrant == 3 || height->quadrant == 4)
		height->current_ver_y = start_tile_pos_y + offsety + b;
}

void	positive_angle(t_wall *height, int angle)
{
	if (angle < 90)
		height->quadrant = 1;
	else
	{
		if (angle >= 90 && angle < 180)
			height->quadrant = 4;
		else if (angle >= 180 && angle < 270)
			height->quadrant = 3;
		else
			height->quadrant = 2;
	}
}

void	negative_angle(t_wall *height, int angle)
{
	if (angle > -90)
		height->quadrant = 2;
	else
	{
		if (angle <= -90 && angle > -180)
			height->quadrant = 3;
		else if (angle <= -180 && angle > -270)
			height->quadrant = 4;
		else
			height->quadrant = 1;
	}
}

void	decide_quadrant(t_wall *height)
{
	double	angle;

	angle = fmod(height->angle + height->p_offset, 360);
	if (height->angle + height->p_offset >= 0)
		positive_angle(height, angle);
	else
		negative_angle(height, angle);
}
