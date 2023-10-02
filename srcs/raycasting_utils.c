/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:42:32 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 12:32:08 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* Here is the short concise pseudocode for the above:
1. Determine angle of the ray
2.  Determine quadrant of the ray
3.  Determine the first intersection point of the ray
4.  Determine the scaling of the ray
5.  Determine the next intersection point of the ray
6.  Determine the distance of the intersection point
7.  Determine which wall the ray has hit
8.  Draw the ray 
*/



#include "cub3d.h"

int	check_horizontal_wall(t_wall *height)
{
	int	wallx;
	int	wally;

	wallx = (height->current_hor_x - TILE) / (TILE);
	if (height->quadrant == 3 || height->quadrant == 4)
		wally = (height->current_hor_y - TILE) / (TILE);
	else
		wally = (height->current_hor_y - TILE) / (TILE) - 1;
	if (wally >= 0 && wally < height->main->height && wallx >= 0 && \
		wallx < (int)ft_strlen(height->main->map[wally]))
	{
		if (height->main->map[wally][wallx] == '1')
			return (1);
	}
	else
		return (2);
	return (0);
}

int	check_vertical_wall(t_wall *height)
{
	int	wallx;
	int	wally;

	if (height->quadrant == 1 || height->quadrant == 4)
		wallx = (height->current_ver_x - TILE) / (TILE);
	else
		wallx = (height->current_ver_x - TILE) / (TILE) - 1;
	wally = (height->current_ver_y - TILE) / TILE;
	if (wally >= 0 && wally < height->main->height && \
		wallx >= 0 && wallx < (int)ft_strlen(height->main->map[wally]))
	{
		if (height->main->map[wally][wallx] == '1')
			return (1);
	}
	else
		return (2);
	return (0);
}

void	count_horizontal_scaling(t_wall *height)
{
	height->horizontal_x_scaling = fabs(TILE / tan(height->real_angle * RADIAN));
	if (fabs(remainder(height->angle + height->p_offset, 180)) == 90)
		height->horizontal_x_scaling = 10000000;
}

void	count_vertical_scaling(t_wall *height)
{
	height->vertical_y_scaling = fabs(tan(height->real_angle * RADIAN) * TILE);
	if (fabs(remainder(height->angle + height->p_offset, 180)) == 0)
		height->vertical_y_scaling = 10000000;
}

double	calculate_dist_draw(t_wall *height, int hor_hit, int ver_hit)
{
	double	magnitude_horizontal_v;
	double	magnitude_vertical_v;

	magnitude_horizontal_v = sqrt(fabs(pow(height->current_hor_x - height->pos_cur_x, 2)) + \
									fabs(pow(height->current_hor_y - height->pos_cur_y, 2)));
	magnitude_vertical_v = sqrt(fabs(pow(height->current_ver_x - height->pos_cur_x, 2)) + \
									fabs(pow(height->current_ver_y - height->pos_cur_y, 2)));
	height->x_ray = false;
	if (fabs(remainder(height->angle + height->p_offset, 180)) == 90)
		magnitude_horizontal_v = magnitude_vertical_v + 10;
	if (fabs(remainder(height->angle + height->p_offset, 180)) == 0)
		magnitude_vertical_v = magnitude_horizontal_v + 10;
	if (ver_hit == 2)
		magnitude_vertical_v = magnitude_horizontal_v + 10;
	if (hor_hit == 2)
		magnitude_horizontal_v = magnitude_vertical_v + 10;
	if (magnitude_horizontal_v < magnitude_vertical_v)
	{
		height->x_ray = true;
		return (magnitude_horizontal_v);
	}
	return (magnitude_vertical_v);
}
