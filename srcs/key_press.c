/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:00:53 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 08:00:53 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int key_press(int keycode, t_data *data)
{
	float dx = 0;
	float dy = 0;

	if (keycode == KEY_W || keycode == KEY_W_LOW) {
		// Move forward
		dx = MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
		dy = -MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
	} 
	else if (keycode == KEY_S || keycode == KEY_S_LOW) {
		// Move backward
		dx = -MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
		dy = MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
	}
	else if (keycode == KEY_A || keycode == KEY_A_LOW) {
		// Strafe left
		dx = -MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
		dy = -MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
	}
	else if (keycode == KEY_D || keycode == KEY_D_LOW) {
		// Strafe right
		dx = MOVE_SPEED * cos(data->player_dir * (M_PI / 180.0));
		dy = MOVE_SPEED * sin(data->player_dir * (M_PI / 180.0));
	}
	else if (keycode == KEY_LEFT) {
		// Turn left
		data->player_dir += ROT_SPEED;
		if (data->player_dir >= 360) {
			data->player_dir -= 360;
		}
	}
	else if (keycode == KEY_RIGHT) {
		// Turn right
		data->player_dir -= ROT_SPEED;
		if (data->player_dir < 0) {
			data->player_dir += 360;
		}
	}
	else if (keycode == KEY_ESC)
		exit(0);  // Exit the game

	// Apply movement.
	move_player(data, dx, dy);
	//raycasting
	render(data);
	// Clear the screen to black before drawing the updated position
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_player(data);

	return (0);
}