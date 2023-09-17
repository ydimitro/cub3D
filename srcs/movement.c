/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:59:27 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 07:59:27 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// check for collisions to ensure that the player doesn't walk into walls, 
//and if the path is clear,
//update the player's x and y coordinates

/*splitting the checks for x and y directions is to allow for sliding movement 
alongside walls. For example, if a player tries to move diagonally into a wall, 
this setup will allow the player to still move parallel 
to the wall instead of being completely stopped.*/

void move_player(t_data *data, float dx, float dy) {
	// Check for collisions in the x direction
	char x_dest_tile = data->map[(int)(data->player_y)][(int)(data->player_x + dx)];
	if (x_dest_tile != '1') { // a wall
		data->player_x += dx;
	}
	
	// Check for collisions in the y direction
	char y_dest_tile = data->map[(int)(data->player_y + dy)][(int)(data->player_x)];
	if (y_dest_tile != '1') {
		data->player_y += dy;
	}
}


/*
void move_player_forward(t_data *data, double distance)
{
	data->player.x += cos(data->player.direction) * distance;
	data->player.y += sin(data->player.direction) * distance;
}

void move_player_backward(t_data *data, double distance)
{
	data->player.x -= cos(data->player.direction) * distance;
	data->player.y -= sin(data->player.direction) * distance;
}

void turn_player_left(t_data *data, double angle)
{
	data->player.direction -= angle;
	if (data->player.direction < 0)
		data->player.direction += 2 * 3.14159;
}

void turn_player_right(t_data *data, double angle)
{
	data->player.direction += angle;
	if (data->player.direction > 2 * 3.14159)
		data->player.direction -= 2 * 3.14159;
}
*/