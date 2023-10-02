/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   wall_collision_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:01:17 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 18:11:31 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_center_and_corners(t_wall *height, t_collision_data *data)
{
	data->center1 = check_wall(height, height->p_m[2], height->p_m[3]);
	data->center2 = check_wall(height, height->p_m[4], height->p_m[5]);
	data->corner1 = check_wall(height, height->p_c[6], height->p_c[7]);
	data->corner2 = check_wall(height, height->p_c[4], height->p_c[5]);
	if ((data->center1 != 0 || data->corner1 != 0) && \
			(data->center2 != 0 || data->corner2 != 0))
		return (check_position(height));
	return (0);
}

int	check_position(t_wall *height)
{
	if ((height->pos_cur_x - TILE) / (TILE) != (height->p_m[6] - TILE) / (TILE))
		return (1);
	if ((height->pos_cur_y - TILE) / (TILE) != (height->p_m[7] - TILE) / (TILE))
		return (1);
	return (0);
}
