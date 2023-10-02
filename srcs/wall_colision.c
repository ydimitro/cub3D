/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_colision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:43:39 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 11:43:40 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	wall_colision_a(t_wall *height, int check_wall_colision)
{
	int	corner1;
	int	corner2;
	int	center1;
	int	center2;

	corner1 = 0;
	corner2 = 0;
	center1 = 0;
	center2 = 0;
	check_wall_colision = check_wall(height, height->p_m[4], height->p_m[5]);
	center1 = check_wall(height, height->p_m[0], height->p_m[1]);
	center2 = check_wall(height, height->p_m[6], height->p_m[7]);
	corner1 = check_wall(height, height->p_c[0], height->p_c[1]);
	corner2 = check_wall(height, height->p_c[4], height->p_c[5]);
	if ((center1 != 0 || corner1 != 0) && (center2 != 0 || corner2 != 0))
	{
		if ((height->pos_cur_x - TILE) / (TILE) != (height->p_m[4] - TILE) / (TILE))
			return (1);
		if ((height->pos_cur_y - TILE) / (TILE) != (height->p_m[5] - TILE) / (TILE))
			return (1);
	}
	return (check_wall_colision);
}

int	wall_colision_s(t_wall *height, int check_wall_colision)
{
	int	corner1;
	int	corner2;
	int	center1;
	int	center2;
	int	mark;

	corner1 = 0;
	corner2 = 0;
	center1 = 0;
	center2 = 0;
	mark = 0;
	check_wall_colision = check_wall(height, height->p_m[6], height->p_m[7]);
	center1 = check_wall(height, height->p_m[2], height->p_m[3]);
	center2 = check_wall(height, height->p_m[4], height->p_m[5]);
	corner1 = check_wall(height, height->p_c[6], height->p_c[7]);
	corner2 = check_wall(height, height->p_c[4], height->p_c[5]);
	if ((center1 != 0 || corner1 != 0) && (center2 != 0 || corner2 != 0))
	{
		if ((height->pos_cur_x - TILE) / (TILE) != (height->p_m[6] - TILE) / (TILE))
			return (1);
		if ((height->pos_cur_y - TILE) / (TILE) != (height->p_m[7] - TILE) / (TILE))
			return (1);
	}
	return (check_wall_colision);
}

int	wall_colision_w(t_wall *height, int check_wall_colision)
{
	int	corner1;
	int	corner2;
	int	center1;
	int	center2;

	corner1 = 0;
	corner2 = 0;
	center1 = 0;
	center2 = 0;
	check_wall_colision = check_wall(height, height->p_m[0], height->p_m[1]);
	center1 = check_wall(height, height->p_m[2], height->p_m[3]);
	center2 = check_wall(height, height->p_m[4], height->p_m[5]);
	corner1 = check_wall(height, height->p_c[2], height->p_c[3]);
	corner2 = check_wall(height, height->p_c[0], height->p_c[1]);
	if ((center1 != 0 || corner1 != 0) && (center2 != 0 || corner2 != 0))
	{
		if ((height->pos_cur_x - TILE) / (TILE) != (height->p_m[0] - TILE) / (TILE))
			return (1);
		if ((height->pos_cur_y - TILE) / (TILE) != (height->p_m[1] - TILE) / (TILE))
			return (1);
	}
	return (check_wall_colision);
}

int	wall_colision_d(t_wall *height, int check_wall_colision)
{
	int	corner1;
	int	corner2;
	int	center1;
	int	center2;

	corner1 = 0;
	corner2 = 0;
	center1 = 0;
	center2 = 0;
	check_wall_colision = check_wall(height, height->p_m[2], height->p_m[3]);
	center1 = check_wall(height, height->p_m[0], height->p_m[1]);
	center2 = check_wall(height, height->p_m[6], height->p_m[7]);
	corner1 = check_wall(height, height->p_c[2], height->p_c[3]);
	corner2 = check_wall(height, height->p_m[6], height->p_m[7]);
	if ((center1 != 0 || corner1 != 0) && (center2 != 0 || corner2 != 0))
	{
		if ((height->pos_cur_x - TILE) / (TILE) != (height->p_m[2] - TILE) / (TILE))
			return (1);
		if ((height->pos_cur_y - TILE) / (TILE) != (height->p_m[3] - TILE) / (TILE))
			return (1);
	}
	return (check_wall_colision);
}

int	wall_colision_check(t_wall *height, int keycode)
{
	int	check_wall_colision;
	int	check_wall_right;
	int	check_wall_left;

	check_wall_colision = 0;
	check_wall_left = 0;
	check_wall_right = 0;
	if (keycode == W_KEY)
		check_wall_colision = wall_colision_w(height, check_wall_colision);
	else if (keycode == S_KEY)
		check_wall_colision = wall_colision_s(height, check_wall_colision);
	else if (keycode == A_KEY)
		check_wall_colision = wall_colision_a(height, check_wall_colision);
	else if (keycode == D_KEY)
		check_wall_colision = wall_colision_d(height, check_wall_colision);
	return (check_wall_colision);
}
