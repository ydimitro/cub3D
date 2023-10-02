/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:06:21 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 17:07:05 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
determining the placement of pixels on the screen using Brezenham algo
for drawing straight lines on a grid without using floating-point arithmetic.

x: 		determines the direction of pixel placement (1 = y || vertical plane)
color:	color of the pixel to be placed

The algorithm determines the points that need to be highlighted 
to represent a line between two given points. The decision_v variable
helps decide whether the next point should be above or below the 
current point, and the direction variable indicates the direction of 
the line. The delta_x and delta_y variables represent the change in x and 
y coordinates, respectively.
*/
static void	place_pixel(t_wall *height, int color)
{
	my_mlx_pixel_put(height->data, height->line[0], height->line[1], color);
}

static void	update_decision(t_wall *height, int delta_primary, \
	int delta_secondary, int *line_index)
{
	if (height->b->decision_v < 0)
		height->b->decision_v += (2 * delta_primary);
	else
	{
		height->b->decision_v += (2 * delta_primary) - (2 * delta_secondary);
		*line_index += height->b->direction;
	}
}

void	pixel_placement_decider(t_wall *height, int x, int color)
{
	place_pixel(height, color);
	if (x == 1)
	{
		update_decision(height, height->b->delta_y, \
			height->b->delta_x, &height->line[1]);
	}
	else
	{
		update_decision(height, height->b->delta_x, \
			height->b->delta_y, &height->line[0]);
	}
}

/*
draw lines on the screen that have a slope between -1 and 1
Set the direction of the line to be positive (going right).
Calculate the change in x and y coordinates for the line.
If the change in y is negative (meaning the line is going upwards),
make the change in y positive and set the direction to be negative (left).
Initialize the decision variable for the Bresenham's algorithm.
Draw the line from the starting x-coordinate to the ending 
x-coordinate with while loop.
*/
void	draw_low_slope(t_wall *height, int color)
{
	height->b->direction = 1;
	height->b->delta_x = height->line[2] - height->line[0];
	height->b->delta_y = height->line[3] - height->line[1];
	if (height->b->delta_y < 0)
	{
		height->b->delta_y = -1 * height->b->delta_y;
		height->b->direction = -1;
	}
	height->b->decision_v = (2 * height->b->delta_y) - height->b->delta_x;
	while (height->line[0] <= height->line[2])
	{
		pixel_placement_decider(height, 1, color);
		height->line[0]++;
	}
}

/*
draw lines on the screen that have a slope between -1 and 1
Same logic for the other plane.
*/
void	draw_high_slope(t_wall *height, int color)
{
	height->b->direction = 1;
	height->b->delta_x = height->line[2] - height->line[0];
	height->b->delta_y = height->line[3] - height->line[1];
	if (height->b->delta_x < 0)
	{
		height->b->delta_x = -1 * height->b->delta_x;
		height->b->direction = -1;
	}
	height->b->decision_v = (2 * height->b->delta_x) - height->b->delta_y;
	while (height->line[1] <= height->line[3])
	{
		pixel_placement_decider(height, 0, color);
		height->line[1]++;
	}
}
