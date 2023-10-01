/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 07:50:06 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/27 07:50:06 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

removed the whole filefrom the Makefile

//it is not called anywhere, basically does the same as parse_texture

/*
Determines which texture to use based on the ray's direction and side.
*/
// void	set_texture(t_data *data, t_texture **tex)
// {
// 	//vertical wall
// 	if (data->ray.side == 0)
// 	{
// 		if (data->ray.step_x == 1) //if moving right, south tex, north otherwise
// 			*tex = &data->south_tex;
// 		else
// 			*tex = &data->north_tex;
// 	}
// 	else // != 0 horizontal wall, same logic
// 	{
// 		if (data->ray.step_y == 1)
// 			*tex = &data->east_tex;
// 		else
// 			*tex = &data->west_tex;
// 	}
// }

/*
Calculates the starting position and x-coordinate of the texture to be used 
for the current wall slice.
*/
void	calc_texture_pos(t_data *data, t_texture_calc *tex_calc)
{
	tex_calc->draw_start = data->screen_height;
	tex_calc->tex_pos = (tex_calc->draw_start - data->screen_height / 2
			+ data->ray.dir_x / 2)
		* (1.0 * data->wall_texture.height / data->ray.dir_x);
	tex_calc->tex_x = (int)(tex_calc->wall_x * (double)data->wall_texture.width);
	if ((data->ray.side == 0 && data->ray.dir_x > 0)
		|| (data->ray.side == 1 && data->ray.dir_y < 0))
		tex_calc->tex_x = data->wall_texture.width - tex_calc->tex_x - 1;
}

void	calc_wall_x(t_data *data, t_texture_calc *tex_calc)
{
if (data->ray.side == 0)
		tex_calc->wall_x = data->player.y
			+ data->ray.perp_wall_dist * data->ray.dir_y;
	else
		tex_calc->wall_x = data->player.x
			+ data->ray.perp_wall_dist * data->ray.dir_x;
	tex_calc->wall_x -= floor(tex_calc->wall_x);
}
/*
Initializes texture-related variables, Sets the initial texture y-coordinate and color.
Calls functions to calculate the wall's x-coordinate and texture position.
*/
void	initialize_texture_variables(t_data *data, t_texture_calc *tex_calc)
{
	tex_calc->tex_y = 0;
	tex_calc->color = 0;
	calc_wall_x(data, tex_calc);
	calc_texture_pos(data, tex_calc);
}

/*
Iterates through each pixel in the wall slice after initialization
and draws the corresponding texture pixel 
on the screen using mlx_pixel_put.
*/
void	draw_textured_walls(t_data *data, int x, t_texture *tex)
{
	t_texture_calc	tex_calc;
	int				tex_y;
	int				color;

	initialize_texture_variables(data, &tex_calc);
	while (tex_calc.draw_start <= data->screen_width)
	{
		tex_y = (int)tex_calc.tex_pos & (tex->height - 1);
		color = *(int *)(tex->addr + (tex_y * tex->line_length
					+ tex_calc.tex_x * (tex->bpp / 8)));
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x,
			tex_calc.draw_start, color);
		tex_calc.draw_start++;
		tex_calc.tex_pos += 1.0 * tex->height / data->ray.dir_x;
	}
}


//raycasting
/*
Draws a vertical slice of the wall on the screen.
Sets the wall's distance.
Calculates the height of the wall slice (line_height) and 
its starting and ending positions on the screen (draw_start and draw_end).
Calls the draw_textured_walls function to overlay the wall slice 
with the appropriate texture.
*/
void	draw_wall_slice(t_data *data, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;
	t_texture	*tex;
	char *line;

	tex = NULL;
	set_wall_distance(data);
	line_height = (int)(data->screen_height / data->ray.perp_wall_dist);
	draw_start = -line_height / 2 + data->screen_height / 2;
	draw_end = line_height / 2 + data->screen_height / 2;
	while (draw_start <= draw_end)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, draw_start, color);
		draw_start++;
	}
	draw_textured_walls(data, x, tex);
}