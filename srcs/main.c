/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:41:16 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 18:40:04 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_wall *wall, int indentifier)
{
	if (indentifier == W_KEY)
	{
		wall->pos_cur_x = wall->p_m[0];
		wall->pos_cur_y = wall->p_m[1];
	}
	if (indentifier == S_KEY)
	{
		wall->pos_cur_x = wall->p_m[6];
		wall->pos_cur_y = wall->p_m[7];
	}
	if (indentifier == A_KEY)
	{
		wall->pos_cur_x = wall->p_m[4];
		wall->pos_cur_y = wall->p_m[5];
	}
	if (indentifier == D_KEY)
	{
		wall->pos_cur_x = wall->p_m[2];
		wall->pos_cur_y = wall->p_m[3];
	}
}

int	key_hook(int keycode, t_wall *wall)
{
	if (keycode == ESC_KEY)
		close_game(wall);
	if (keycode == LEFT_KEY)
		wall->angle += 5;
	else if (keycode == RIGHT_KEY)
		wall->angle -= 5;
	else
	{
		if (wall_colision_check(wall, keycode) == 0)
			move_player(wall, keycode);
	}
	return (0);
}

int	render(t_wall *height)
{
	height->data->img = mlx_new_image(height->vars->mlx, S_WIDTH, S_HEIGHT);
	height->data->addr = mlx_get_data_addr(height->data->img, \
		&height->data->bits_per_pixel, \
		&height->data->line_length, &height->data->endian);
	draw_player(height);
	draw_2d_rays(height);
	mlx_put_image_to_window(height->vars->mlx, height->vars->win, \
		height->data->img, 0, 0);
	mlx_destroy_image(height->vars->mlx, height->data->img);
	return (0);
}

void	hooks_n_loops(t_wall *wall)
{
	wall->pos_cur_x = TILE + (wall->main->p_x * (TILE)) + ((TILE) / 2);
	wall->pos_cur_y = TILE + (wall->main->p_y * (TILE)) + ((TILE) / 2);
	mlx_hook(wall->vars->win, 2, (1L) << 0, &key_hook, wall);
	mlx_hook(wall->vars->win, 17, 0L, close_game, wall);
	mlx_loop_hook(wall->vars->mlx, &render, wall);
	mlx_loop(wall->vars->mlx);
}

int	main(int argc, char **argv)
{
	t_wall	*wall;
	t_main	*main;

	wall = NULL;
	wall = ft_calloc(sizeof(t_wall), 1);
	main = ft_calloc(sizeof(t_main), 1);
	initialize_main(main);
	initialize_wall(wall, main);
	check_basic_errors(main, argc, argv);
	parsing(main, argv);
	position_offset(main, wall);
	initialize_mlx(wall->data, wall->vars);
	load_assets(wall);
	hooks_n_loops(wall);
	return (0);
}
