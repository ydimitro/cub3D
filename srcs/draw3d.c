
#include "../includes/cub3d.h"

int	my_mlx_pixel_get(t_wall *h, t_texture *texture, int x, int y)
{
	char	*color;

	color = texture->data + (y * texture->size_line + x * (texture->bpp / 8));
	if (h->x_ray == true)
		return (*(int *)color);
	return (*(int *)color >> 1 & 8355711);
}

int	get_start_row(double line_h)
{
	if (line_h > S_HEIGHT)
		return ((line_h - S_HEIGHT) / 2);
	return (0);
}

t_texture	*choose_texture(t_wall *h)
{
	if (h->x_ray == true)
	{
		if (h->quadrant == 1 || h->quadrant == 2)
			return (h->wall_tex->texture_north);
		return (h->wall_tex->texture_south);
	}
	if (h->quadrant == 1 || h->quadrant == 4)
		return (h->wall_tex->texture_east);
	return (h->wall_tex->texture_west);
}

void	draw_vertical_line(t_wall *h, double temp_line_h)
{
	int			y1;
	int			row;
	int			column;
	int			ver_tex_line;
	t_texture	*texture;

	y1 = h->line[1];
	row = get_start_row(temp_line_h);
	ver_tex_line = 0;
	texture = choose_texture(h);
	h->tex_to_tile_ratio_x = texture->w / (double)TILE;
	h->tex_to_line_h_ratio_y = texture->h / temp_line_h;
	if (h->x_ray == true)
		ver_tex_line = fmod(h->current_hor_x, TILE);
	else
		ver_tex_line = fmod(h->current_ver_y, TILE);
	column = ver_tex_line * h->tex_to_tile_ratio_x;
	while (y1 != h->line[3])
	{
		my_mlx_pixel_put(h->data, h->line[0], y1, \
		my_mlx_pixel_get(h, texture, column, row * h->tex_to_line_h_ratio_y));
		row++;
		y1++;
	}
}

void	draw_3d(t_wall *h, int a, double fov)
{
	double	line_h;
	double	fish_eye;
	double	temp_line_h;

	fish_eye = fabs(h->shortest_dist_to_wall * cos(fov * RADIAN));
	line_h = fabs((TILE / fish_eye) * h->p_dist_from_projection_plane);
	temp_line_h = line_h;
	if (line_h > S_HEIGHT)
		line_h = S_HEIGHT;
	h->line[0] = a;
	h->line[2] = a;
	h->line[1] = (S_HEIGHT / 2) - (line_h / 2);
	h->line[3] = (S_HEIGHT / 2) + (line_h / 2);
	draw_vertical_line(h, temp_line_h);
	h->line[1] = (S_HEIGHT / 2) + (line_h / 2);
	h->line[3] = S_HEIGHT;
	draw_line(h, h->main->ground);
	h->line[1] = (S_HEIGHT / 2) - (line_h / 2);
	h->line[3] = 0;
	draw_line(h, h->main->roof);
}
