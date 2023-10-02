/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:05:01 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 17:05:38 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Swapping the starting and ending coordinates of a line segment
to ensure that a line is always drawn from a specific starting/ending point.
*/
static void	rotate(t_wall *height)
{
	int	temp_x;
	int	temp_y;

	temp_x = height->line[0];
	temp_y = height->line[1];
	height->line[0] = height->line[2];
	height->line[2] = temp_x;
	height->line[1] = height->line[3];
	height->line[3] = temp_y;
}

/*
Drawing a line segment on the screen based on its slope.
*/
void	draw_line(t_wall *height, int color)
{
	if (fabs((double)height->line[3] - (double)height->line[1]) <= \
						fabs((double)height->line[2] - (double)height->line[0]))
	{
		if (height->line[0] > height->line[2])
		{
			rotate(height);
			draw_low_slope(height, color);
		}
		else
			draw_low_slope(height, color);
	}
	else
	{
		if (height->line[1] > height->line[3])
		{
			rotate(height);
			draw_high_slope(height, color);
		}
		else
			draw_high_slope(height, color);
	}
}
