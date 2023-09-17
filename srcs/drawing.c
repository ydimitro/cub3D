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


void draw_player(t_data *data)
{
	int player_screen_x = (int)(data->player.x * 10);  // 10 is just for scale, adjust as needed
	int player_screen_y = (int)(data->player.y * 10);  // same scale

	// Draw a circle to represent the player
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, player_screen_x, player_screen_y, 0xFFFFFF);  // player's position
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, player_screen_x+1, player_screen_y, 0xFFFFFF);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, player_screen_x-1, player_screen_y, 0xFFFFFF);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, player_screen_x, player_screen_y+1, 0xFFFFFF);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, player_screen_x, player_screen_y-1, 0xFFFFFF);

	// Draw a line to represent the direction the player is facing
	int end_x = (int)(player_screen_x + cos(data->player.direction) * 20);  // 20 is the line's length
	int end_y = (int)(player_screen_y + sin(data->player.direction) * 20);

	// Simple Bresenham's line algorithm without loops:
	int dx = abs(end_x - player_screen_x);
	int dy = abs(end_y - player_screen_y);
	int sx = (player_screen_x < end_x) ? 1 : -1;
	int sy = (player_screen_y < end_y) ? 1 : -1;
	int err = dx - dy;

	while (player_screen_x != end_x || player_screen_y != end_y) 
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, player_screen_x, player_screen_y, 0xFFFFFF);

		int e2 = err << 1;
		if (e2 > -dy) 
		{
			err -= dy;
			player_screen_x += sx;
		}
		if (e2 < dx) 
		{
			err += dx;
			player_screen_y += sy;
		}
	}
}

void draw_textured_walls(t_data *data, int x)
{
	// Choose the texture based on wall direction
	t_texture *tex;
	if (data->ray.side == 0)
		tex = (data->ray.step_x == 1) ? &data->south_tex : &data->north_tex;
	else
		tex = (data->ray.step_y == 1) ? &data->east_tex : &data->west_tex;

	// Calculate which part of the texture to use
	double wall_x;
	if (data->ray.side == 0)
		wall_x = data->player.y + data->ray.perp_wall_dist * data->ray.dir_y;
	else
		wall_x = data->player.x + data->ray.perp_wall_dist * data->ray.dir_x;
	wall_x -= floor(wall_x);

	int tex_x = (int)(wall_x * (double)tex->width);
	if (data->ray.side == 0 && data->ray.dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (data->ray.side == 1 && data->ray.dir_y < 0)
		tex_x = tex->width - tex_x - 1;

	double step = 1.0 * tex->height / line_height;
	double tex_pos = (draw_start - data->screen_height / 2 + line_height / 2) * step;

	while (draw_start <= draw_end)
	{
		int tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;

		// Get the texture color
		int color = *(int *)(tex->addr + (tex_y * tex->line_length + tex_x * (tex->bpp / 8)));

		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, draw_start, color);
		draw_start++;
	}
}


/*
void set_pixel(t_data *data, int x, int y, int color)
{
	int pixel_index = y * data->size_line + x * (data->bits_per_pixel / 8);

	data->img_data[pixel_index] = color & 0xFF;
	data->img_data[pixel_index + 1] = (color & 0xFF00) >> 8;
	data->img_data[pixel_index + 2] = (color & 0xFF0000) >> 16;
}

void fill_row(t_data *data, int x, int y, int end_x, int color)
{
	if (x < end_x)
	{
		set_pixel(data, x, y, color);
		fill_row(data, x + 1, y, end_x, color);
	}
}

void draw_rectangle_recursive(t_data *data, int x, int y, int width, int height, int color)
{
	if (height == 0) return;

	fill_row(data, x, y, x + width, color);
	draw_rectangle_recursive(data, x, y + 1, width, height - 1, color);
}

void draw_rectangle(t_data *data, int x, int y, int width, int height, int color)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, 800, 600);
	data->img_data = mlx_get_data_addr(data->img_ptr, &(data->bits_per_pixel), 
										&(data->size_line), &(data->endian));

	draw_rectangle_recursive(data, x, y, width, height, color);

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

*/