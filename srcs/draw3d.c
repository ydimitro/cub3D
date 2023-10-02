/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:40:09 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 16:57:17 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Retrieving the color of a pixel from a texture.
1. Memory access calculation.
2. Retrieving color with x-ray
3. Retrieving modified color without x-ray
"*(int *)color >> 1": halves the brightness of the color.
"& 8355711": ensures that the color value does not exceed the maximum 
allowable value for each RGB channel. It also adds a slight tint to the color.
*/
int	my_mlx_pixel_get(t_wall *height, t_texture *texture, int x, int y)
{
	char	*color;

	color = texture->data + (y * texture->size_line + x * (texture->bpp / 8));
	if (height->x_ray == true)
		return (*(int *)color);
	return (*(int *)color >> 1 & 8355711);
}

/*
Determining the starting row for drawing a line.
If the line height (line_h) is greater than the screen height (S_HEIGHT), 
it returns the difference divided by 2.
*/
int	get_start_row(double line_h)
{
	if (line_h > S_HEIGHT)
		return ((line_h - S_HEIGHT) / 2);
	return (0);
}

/*
Selecting the appropriate texture based on the quadrant and x_ray flag.
If x_ray is true, it chooses between the north and south textures.
*/
t_texture	*choose_texture(t_wall *height)
{
	if (height->x_ray == true)
	{
		if (height->quadrant == 1 || height->quadrant == 2)
			return (height->wall_tex->texture_north);
		return (height->wall_tex->texture_south);
	}
	if (height->quadrant == 1 || height->quadrant == 4)
		return (height->wall_tex->texture_east);
	return (height->wall_tex->texture_west);
}

/*
Drawing a vertical line on the screen.

It determines the starting row and chooses the appropriate texture.
It calculates the texture-to-tile ratio and the texture-to-line height ratio.
It then draws the line pixel by pixel using the my_mlx_pixel_put function.
*/
void	draw_vertical_line(t_wall *height, double temp_line_h)
{
	int			y1;
	int			row;
	int			column;
	int			ver_tex_line;
	t_texture	*texture;

	y1 = height->line[1];
	row = get_start_row(temp_line_h);
	ver_tex_line = 0;
	texture = choose_texture(height);
	height->tex_to_tile_ratio_x = texture->width / (double)TILE;
	height->tex_to_line_h_ratio_y = texture->height / temp_line_h;
	if (height->x_ray == true)
		ver_tex_line = fmod(height->current_hor_x, TILE);
	else
		ver_tex_line = fmod(height->current_ver_y, TILE);
	column = ver_tex_line * height->tex_to_tile_ratio_x;
	while (y1 != height->line[3])
	{
		my_mlx_pixel_put(height->data, height->line[0], y1, \
		my_mlx_pixel_get(height, texture, column, row * \
			height->tex_to_line_h_ratio_y));
		row++;
		y1++;
	}
}

/*
Drawing a 3D projection of the wall.

It calculates the line height by correcting for the fish-eye effect.

(The fish-eye effect occurs due to the nature of raycasting. 
Rays cast at angles further from the center have longer distances.)

It calculates line height. (height->p_dist_from_projection_plane is
the distance from the player to the projection plane (the screen).)

It sets the starting and ending points for the line.
It then draws the vertical line representing the wall.
Finally, it draws the floor and ceiling sections.
*/

void	draw_3d(t_wall *height, int a, double fov)
{
	double	line_h;
	double	fish_eye;
	double	temp_line_h;

	fish_eye = fabs(height->shortest_dist_to_wall * cos(fov * RADIAN));
	line_h = fabs((TILE / fish_eye) * height->p_dist_from_projection_plane);
	temp_line_h = line_h;
	if (line_h > S_HEIGHT)
		line_h = S_HEIGHT;
	height->line[0] = a;
	height->line[2] = a;
	height->line[1] = (S_HEIGHT / 2) - (line_h / 2);
	height->line[3] = (S_HEIGHT / 2) + (line_h / 2);
	draw_vertical_line(height, temp_line_h);
	height->line[1] = (S_HEIGHT / 2) + (line_h / 2);
	height->line[3] = S_HEIGHT;
	draw_line(height, height->main->floor);
	height->line[1] = (S_HEIGHT / 2) - (line_h / 2);
	height->line[3] = 0;
	draw_line(height, height->main->ceiling);
}
