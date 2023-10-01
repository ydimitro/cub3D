/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:50:06 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 07:50:06 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/*
This function draws a small cross-shaped pattern on the screen at 
the specified (x, y) coordinates. The pattern is intended to represent 
a circle or point on the screen.
*/
void	draw_circle(t_data *data, int x, int y)
{
	int	color;

	color = 0xFFFFFF;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + 1, y, color);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x - 1, y, color);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y + 1, color);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y - 1, color);
}

/*
sets the endpoint for a line representing the player's direction.
Should be called before any rendering or drawing.
*20 = how far out the endpoint of the line (player's dir) should be from
its starting point. With factor 20 the line is better visible
*/
void	set_line_endpoints(t_data *data, t_line *line)
{
	//horizontal ray
	printf("side:%d\n", data->ray.side);
	if (data->ray.side == 0)
	{
		if (data->ray.dir_x > 0)
			line->end_x = (int)(line->start_x + cos(data->player.dir) * 20);
		else
			line->end_x = (int)(line->start_x - cos(data->player.dir) * 20);
	}
	//vertical ray
	if (data->ray.side == 1)
	{
		if (data->ray.dir_y > 0)
			line->end_y = (int)(line->start_y + sin(data->player.dir) * 20);
		else
			line->end_y = (int)(line->start_y - sin(data->player.dir) * 20);
	}
}

/*
the player is represented by a circle and a line. 
*/
void	draw_player(t_data *data)
{
	t_line line;

	line.end_x = 0;
	line.end_y = 0;
	line.start_x = (int)(data->player.x * 10);
	line.start_y = (int)(data->player.y * 10);
	set_line_endpoints(data, &line);
	draw_circle(data, line.start_x, line.start_y);
	printf("end_x: %d | end_y: %d\n", line.end_x, line.end_y);
	draw_line(data, &line);
}

/*
Bresenham's line algorithm, a way to draw lines on a grid (like pixels on a screen) 
without using floating-point arithmetic.
*/
void	draw_line(t_data *data, t_line *line)
{
	t_line_params	params;
	int				e2;
	int i = 0;

	calc_deltas_and_steps(line, &params);
	if (params.dx > params.dy)
		params.err = params.dx / 2;
	else
		params.err = -params.dy / 2;
	while (line->start_x != line->end_x || line->start_y != line->end_y)
	{
		printf("x:%d|y:%d\n", line->start_x, line->start_y);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			line->start_x, line->start_y, 0xFFFFFF);
		e2 = params.err;
		if (e2 > -params.dy)
		{
			params.err -= params.dy;
			line->start_x += params.sx;
		}
		if (e2 < params.dx)
		{
			params.err += params.dx;
			line->start_y += params.sy;
		}
		if (i == 500)
			exit(1);
		i++;
	}
}
