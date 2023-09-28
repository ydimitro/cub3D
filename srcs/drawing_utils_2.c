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

int	custom_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	calc_line_dir(t_data *data, t_line *line)
{
	data->ray.dir_x = custom_abs(line->end_x - line->start_x);
	data->ray.dir_y = custom_abs(line->end_y - line->start_y);
	if (line->start_x < line->end_x)
		data->ray.side = 1;
	else
		data->ray.side = 0;
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

//draw_line()
void	calc_deltas_and_steps(t_line *line, t_line_params *params)
{
	params->dx = custom_abs(line->end_x - line->start_x);
	params->dy = custom_abs(line->end_y - line->start_y);
	if (line->start_x < line->end_x)
		params->sx = 1;
	else
		params->sx = -1;
	if (line->start_y < line->end_y)
		params->sy = 1;
	else
		params->sy = -1;
}

//raycasting
int	get_wall_color(t_data *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.step_x == 1)
			return (0xFF0000);
		else
			return (0x00FF00);
	}
	else
	{
		if (data->ray.step_y == 1)
			return (0x0000FF);
		else
			return (0xFFFF00);
	}
}