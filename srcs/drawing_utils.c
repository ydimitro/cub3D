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

#include "../includes/cub3d.h"

void	set_texture(t_data *data, t_texture **tex)
{
	if (data->ray.side == 0)
	{
		if (data->ray.step_x == 1)
			*tex = &data->south_tex;
		else
			*tex = &data->north_tex;
	}
	else
	{
		if (data->ray.step_y == 1)
			*tex = &data->east_tex;
		else
			*tex = &data->west_tex;
	}
}

void calculate_wall_x(t_data *data, t_texture_calc *tex_calc)
{
    if (data->ray.side == 0)
        tex_calc->wall_x = data->player.y + data->ray.perp_wall_dist * data->ray.dir_y;
    else
        tex_calc->wall_x = data->player.x + data->ray.perp_wall_dist * data->ray.dir_x;
    tex_calc->wall_x -= floor(tex_calc->wall_x);
}

void calculate_texture_pos(t_data *data, t_texture_calc *tex_calc)
{
    tex_calc->draw_start = data->screen_height;
    tex_calc->tex_pos = (tex_calc->draw_start - data->screen_height / 2 + data->ray.dir_x / 2) * (1.0 * data->tex->height / data->ray.dir_x);
    tex_calc->tex_x = (int)(tex_calc->wall_x * (double)data->tex->width);
    if ((data->ray.side == 0 && data->ray.dir_x > 0) || (data->ray.side == 1 && data->ray.dir_y < 0))
        tex_calc->tex_x = data->tex->width - tex_calc->tex_x - 1;
}

void	calculate_line_dir(t_data *data, t_line *line)
{
	data->ray.dir_x = custom_abs(line->end_x - line->start_x);
	data->ray.dir_y  = custom_abs(line->end_y - line->start_y);
	
	if (line->start_x < line->end_x)
		data->ray.side = 1;
	else
		data->ray.side = 0;
}
