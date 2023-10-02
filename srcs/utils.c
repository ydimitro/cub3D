

#include "../includes/cub3d.h"

void	position_offset(t_main *main, t_wall *wall)
{
	if (main->p_dir == 'N')
		wall->p_offset = 0;
	else if (wall->main->p_dir == 'E')
		wall->p_offset = 90;
	else if (wall->main->p_dir == 'S')
		wall->p_offset = 180;
	else if (wall->main->p_dir == 'W')
		wall->p_offset = 270;
}

int	check_wall(t_wall *h, int x_future, int y_future)
{
	int	wallx;
	int	wally;

	wallx = (x_future - TILE) / (TILE);
	wally = (y_future - TILE) / (TILE);
	if (wally >= 0 && wally < h->main->height && wallx >= 0 && \
		wallx < (int)ft_strlen(h->main->map[wally]))
	{
		if (h->main->map[wally][wallx] == '1')
			return (1);
	}
	else
		return (2);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < S_WIDTH && y < S_HEIGHT && x > 0 && y > 0)
	{
		dst = data->addr + (y * data->line_length + x * \
												(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	player_center_rotation(t_wall *h, double tmp_x, double c, double s)
{
	tmp_x = h->p_c[0];
	h->p_c[0] = ((h->p_c[0] - h->p_c_x) * c - \
					(h->p_c[1] - h->p_c_y) * s) + h->p_c_x;
	h->p_c[1] = ((tmp_x - h->p_c_x) * s + \
					(h->p_c[1] - h->p_c_y) * c) + h->p_c_y;
	tmp_x = h->p_c[2];
	h->p_c[2] = ((h->p_c[2] - h->p_c_x) * c - \
					(h->p_c[3] - h->p_c_y) * s) + h->p_c_x;
	h->p_c[3] = ((tmp_x - h->p_c_x) * s + \
					(h->p_c[3] - h->p_c_y) * c) + h->p_c_y;
	tmp_x = h->p_c[4];
	h->p_c[4] = ((h->p_c[4] - h->p_c_x) * c - \
					(h->p_c[5] - h->p_c_y) * s) + h->p_c_x;
	h->p_c[5] = ((tmp_x - h->p_c_x) * s + \
					(h->p_c[5] - h->p_c_y) * c) + h->p_c_y;
	tmp_x = h->p_c[6];
	h->p_c[6] = ((h->p_c[6] - h->p_c_x) * c - \
					(h->p_c[7] - h->p_c_y) * s) + h->p_c_x;
	h->p_c[7] = ((tmp_x - h->p_c_x) * s + \
					(h->p_c[7] - h->p_c_y) * c) + h->p_c_y;
}

void	load_assets(t_wall *h)
{
	if (h->main->north_t != NULL)
		load_texure(h->wall_tex->texture_north, h, h->main->north_t);
	else
		load_texure(h->wall_tex->texture_north, h, D_NO);
	if (h->main->south_t != NULL)
		load_texure(h->wall_tex->texture_south, h, h->main->south_t);
	else
		load_texure(h->wall_tex->texture_south, h, D_SO);
	if (h->main->east_t != NULL)
		load_texure(h->wall_tex->texture_east, h, h->main->east_t);
	else
		load_texure(h->wall_tex->texture_east, h, D_EA);
	if (h->main->west_t != NULL)
		load_texure(h->wall_tex->texture_west, h, h->main->west_t);
	else
		load_texure(h->wall_tex->texture_west, h, D_WE);
	if (h->main->ground == -1)
		h->main->ground = D_F;
	if (h->main->roof == -1)
		h->main->roof = D_C;
}
