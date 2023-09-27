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
#include "../includes/cub3d.h"

void	draw_circle(t_data *data, int x, int y)
{
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + 1, y, 0xFFFFFF);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x - 1, y, 0xFFFFFF);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y + 1, 0xFFFFFF);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y - 1, 0xFFFFFF);
}

void	draw_player(t_data *data, t_line *line)
{
	line->start_x = (int)(data->player.x * 10);
	line->start_y = (int)(data->player.y * 10);
	if (data->ray.side == 0)
	{
		if (data->ray.dir_x > 0)
			line->end_x = (int)(line->start_x + cos(data->player.dir) * 20);
		else
			line->end_x = (int)(line->start_x - cos(data->player.dir) * 20);
	}
	if (data->ray.side == 1)
	{
		if (data->ray.dir_y > 0)
			line->end_y = (int)(line->start_y + sin(data->player.dir) * 20);
		else
			line->end_y = (int)(line->start_y - sin(data->player.dir) * 20);
	}
	draw_circle(data, line->start_x, line->start_y);
	draw_line(data, line);
}

void	draw_textured_walls(t_data *data, int x, t_texture *tex)
{
	t_texture_calc	tex_calc;
	int				tex_y;
	int				color;

	tex_y = 0;
	color = 0;
	calculate_wall_x(data, &tex_calc);
	calculate_texture_pos(data, &tex_calc);
	while (tex_calc.draw_start <= data->screen_width)
	{
		tex_y = (int)tex_calc.tex_pos & (tex->height - 1);
		color = *(int *)(tex->addr + (tex_y * tex->line_length + tex_calc.tex_x * (tex->bpp / 8)));
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, tex_calc.draw_start, color);
		tex_calc.draw_start++;
		tex_calc.tex_pos += 1.0 * tex->height / data->ray.dir_x;
    }
}

void	draw_line(t_data *data, t_line *line)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	calculate_line_dir(data, line);
	err = dx - dy;
	while (line->start_x != line->end_x || line->start_y != line->end_y)
	{

		e2 = err * 2;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->start_x, line->start_y, 0xFFFFFF);
		if (e2 > -dy)
		{
			err -= dy;
			line->start_x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			line->start_y += sy;
		}
	}
}
