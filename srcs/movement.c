/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:00:53 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 08:00:53 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_movement(int keycode, t_data *data, float *dx, float *dy)
{
	if (keycode == KEY_W || keycode == KEY_W_LOW)
	{
		*dx = MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
		*dy = -MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
	}
	else if (keycode == KEY_S || keycode == KEY_S_LOW)
	{
		*dx = -MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
		*dy = MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
	}
	else if (keycode == KEY_A || keycode == KEY_A_LOW)
	{
		*dx = -MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
		*dy = -MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
	}
	else if (keycode == KEY_D || keycode == KEY_D_LOW)
	{
		*dx = MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
		*dy = MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
	}
}

void	handle_rotation(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT)
	{
		data->player_dir += ROT_SPEED;
		if (data->player_dir >= 360)
			data->player_dir -= 360;
	}
	else if (keycode == KEY_RIGHT)
	{
		data->player_dir -= ROT_SPEED;
		if (data->player_dir < 0)
			data->player_dir += 360;
	}
}

int	key_press(int keycode, t_data *data)
{
	float	dx;
	float	dy;
	t_line	line;

	dx = 0;
	dy = 0;
	line.start_x = 0;
	line.start_y = 0;
	line.end_x = 0;
	line.end_y = 0;
	handle_movement(keycode, data, &dx, &dy);
	handle_rotation(keycode, data);
	if (keycode == KEY_ESC)
		exit(0);
	move_player(data, dx, dy);
	render(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	printf("test\n");
	draw_player(data, &line);
	return (0);
}

//checking for collisions in x and y direction where 1 = wall
void	move_player(t_data *data, float dx, float dy)
{
	char	x_dest_tile;
	char	y_dest_tile;

	x_dest_tile = data->game_map[(int)(data->player.y)][(int)(data->player.x + dx)];
	if (x_dest_tile != '1')
		data->player.x += dx;
	y_dest_tile = data->game_map[(int)(data->player.y + dy)][(int)(data->player.x)];
	if (y_dest_tile != '1')
		data->player.y += dy;
}
