/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:41:05 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 16:16:57 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Initializing the members of the t_main struct to default state. 
*/
void	initialize_main(t_main *main)
{
	main->file_fd = -1;
	main->p_dir = '0';
	main->p_pos_x = 0;
	main->p_pos_y = 0;
	main->p_x = 0;
	main->p_y = 0;
	main->height = 0;
	main->north_t = NULL;
	main->south_t = NULL;
	main->west_t = NULL;
	main->east_t = NULL;
	main->floor = -1;
	main->ceiling = -1;
	main->map = NULL;
}

/*
Allocates memory for various structures related to the wall 
and initializing some of its members.
*/
void	calloc_struct(t_wall *wall)
{
	wall->data = ft_calloc(sizeof(t_data), 1);
	wall->vars = ft_calloc(sizeof(t_vars), 1);
	wall->b = ft_calloc(sizeof(t_brez), 1);
	wall->wall_tex = ft_calloc(sizeof(t_wall_tex), 1);
	wall->wall_tex->texture_north = ft_calloc(sizeof(t_texture), 1);
	wall->wall_tex->texture_south = ft_calloc(sizeof(t_texture), 1);
	wall->wall_tex->texture_west = ft_calloc(sizeof(t_texture), 1);
	wall->wall_tex->texture_east = ft_calloc(sizeof(t_texture), 1);
	wall->b->decision_v = 0;
	wall->b->delta_x = 0;
	wall->b->delta_y = 0;
	wall->b->direction = 0;
}

/*
Initializing the members of the t_wall structure and calling the 
calloc_struct function to allocate memory for its substructures.
*/
void	initialize_wall(t_wall *wall, t_main *main)
{
	int	i;

	calloc_struct(wall);
	i = 0;
	wall->move = 15;
	if (wall->move < 5)
	{
		free(wall);
		parsing_cleaning(main, NULL, SPEED_TO_LITTLE);
	}
	wall->angle = 0;
	wall->p_offset = 0;
	wall->one_colum_increase = (double)60 / S_WIDTH;
	wall->p_dist_from_projection_plane = (S_WIDTH / 2) / tan(30 * RADIAN);
	while (i < 8)
	{
		if (i < 4)
			wall->line[i] = 0;
		wall->p_c[i] = 0;
		wall->p_m[i++] = 0;
	}
	wall->main = main;
}

/*
Initializing the MiniLibX (a graphics library) variables and structures.
*/
void	initialize_mlx(t_data *img, t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	img->img = mlx_new_image(vars->mlx, S_WIDTH, S_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}
