/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:40:55 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 16:56:04 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Destroying and freeing the memory associated with the wall textures.
*/
void	destroy_wall_texures(t_wall *wall)
{
	if (wall->wall_tex->texture_east != NULL)
	{
		mlx_destroy_image(wall->vars->mlx, wall->wall_tex->texture_east->img);
		free(wall->wall_tex->texture_east);
	}
	if (wall->wall_tex->texture_north != NULL)
	{
		mlx_destroy_image(wall->vars->mlx, wall->wall_tex->texture_north->img);
		free(wall->wall_tex->texture_north);
	}
	if (wall->wall_tex->texture_south != NULL)
	{
		mlx_destroy_image(wall->vars->mlx, wall->wall_tex->texture_south->img);
		free(wall->wall_tex->texture_south);
	}
	if (wall->wall_tex->texture_west != NULL)
	{
		mlx_destroy_image(wall->vars->mlx, wall->wall_tex->texture_west->img);
		free(wall->wall_tex->texture_west);
	}
	free(wall->wall_tex);
}

/*
Freeing the memory associated with the t_wall structure.
*/
void	freeing_wall(t_wall *wall)
{
	if (wall->b != NULL)
		free(wall->b);
	destroy_wall_texures(wall);
	mlx_destroy_window(wall->vars->mlx, wall->vars->win);
	if (wall->data != NULL)
		free(wall->data);
	if (wall->vars != NULL)
		free(wall->vars);
	clear_the_main_struct(wall->main);
	free(wall->main);
	free(wall);
}

/*
Cleaning up after parsing, freeing any allocated memory and 
exiting with a specific error code.
*/
void	parsing_cleaning(t_main *main, char *arr, int err)
{
	if (arr != NULL)
		free(arr);
	clear_the_main_struct(main);
	free(main);
	ft_exiterr(err);
}

int	close_game(t_wall *wall)
{
	freeing_wall(wall);
	exit(0);
}

/*
Freeing the memory associated with the game and then exiting.
*/
void	clear_the_main_struct(t_main *main)
{
	int	i;

	i = 0;
	if (main->file_fd > 2)
		close(main->file_fd);
	if (main->north_t != NULL)
		free(main->north_t);
	if (main->south_t != NULL)
		free(main->south_t);
	if (main->west_t != NULL)
		free(main->west_t);
	if (main->east_t != NULL)
		free(main->east_t);
	if (main->map != NULL)
	{
		while (main->map[i] != NULL)
			free(main->map[i++]);
		free(main->map);
	}
}
