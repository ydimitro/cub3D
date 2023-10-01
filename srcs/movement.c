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
	printf("code:%d\n", keycode);
	if (keycode == KEY_W || keycode == KEY_W_LOW)
	{
		*dx = MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
		*dy = -MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
		data->ray.side = 1;
	}
	else if (keycode == KEY_S || keycode == KEY_S_LOW)
	{
		*dx = -MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
		*dy = MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
		data->ray.side = 1;
	}
	else if (keycode == KEY_A || keycode == KEY_A_LOW)
	{
		*dx = -MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
		*dy = -MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
		data->ray.side = 0;
	}
	else if (keycode == KEY_D || keycode == KEY_D_LOW)
	{
		*dx = MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
		*dy = MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
		data->ray.side = 0;
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

	dx = 0;
	dy = 0;
	printf("0x:%f | y: %f\n", data->player.x, data->player.y);

	handle_movement(keycode, data, &dx, &dy);
	printf("1x:%f | y: %f\n", data->player.x, data->player.y);
	handle_rotation(keycode, data);
	if (keycode == KEY_ESC)
		exit(0);
	printf("2x:%f | y: %f\n", data->player.x, data->player.y);
	move_player(data, dx, dy);
	printf("MOVE PLAYER DONE\n");
	render(data);
	printf("RENDER DONE\n");
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	printf("WINDOW CLEAR DONE\n");
	//draw_player(data);
	printf("DRAW PLAYER DONE\n");
	return (0);
}

//checking for collisions in x and y direction where 1 = wall
void	move_player(t_data *data, float dx, float dy)
{
	char	dest_tile;

	

	// printf("=%c\n", data->game_map[(int)(data->player.y)][(int)(data->player.x + dx)]);
	if ((int)(data->player.x + dx) >= data->game_map_size)
	{
		printf("dx:%f | dy: %f\n", dx, dy);
		printf("3x:%f | y: %f\n", data->player.x, data->player.y);
		printf("size:%d \nout of bounds\n",data->game_map_size );
		exit(5);
	}
	dest_tile = data->game_map[(int)(data->player.x + dx)][(int)(data->player.y + dy)];
	if (dest_tile != '1')
	{
		data->player.x += dx;
		data->player.y += dy;
	}
}
