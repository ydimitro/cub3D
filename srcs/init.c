
#include "../includes/cub3d.h"

/**
 * FILE (init.c) FUNCTION (initialize_main):
 * initializes all of the information in t_main struct to default state. 
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
	main->ground = -1;
	main->roof = -1;
	main->map = NULL;
}

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

void	initialize_mlx(t_data *img, t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	img->img = mlx_new_image(vars->mlx, S_WIDTH, S_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}
