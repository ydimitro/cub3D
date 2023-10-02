
#include "../includes/cub3d.h"

void	first_horizontal(t_wall *h, int start_tile_pos_x, int start_tile_pos_y)
{
	double	a;
	int		offsetx;
	int		offsety;

	offsetx = h->p_c_x - start_tile_pos_x;
	if (h->quadrant == 4 || h->quadrant == 3)
		offsety = start_tile_pos_y + (TILE) - h->p_c_y;
	else
		offsety = h->p_c_y - start_tile_pos_y;
	if (fabs(remainder(h->angle + h->p_offset, 180)) == 90)
		a = 10000000;
	else
		a = fabs(offsety / tan(h->real_angle * RADIAN));
	h->current_hor_len = a / cos(h->real_angle * RADIAN);
	h->current_hor_x = start_tile_pos_x + offsetx + a;
	if (h->quadrant == 3 || h->quadrant == 4)
		h->current_hor_y = h->p_c_y + offsety;
	else
		h->current_hor_y = start_tile_pos_y;
	if (h->quadrant == 3 || h->quadrant == 2)
		h->current_hor_x = start_tile_pos_x + offsetx - a;
}

void	first_vertical(t_wall *h, int start_tile_pos_x, int start_tile_pos_y)
{
	double	a;
	double	b;
	int		offsety;

	offsety = h->p_c_y - start_tile_pos_y;
	if (h->quadrant == 1 || h->quadrant == 4)
		a = start_tile_pos_x + (TILE) - h->p_c_x;
	else
		a = h->p_c_x - start_tile_pos_x;
	if (fabs(remainder(h->angle + h->p_offset, 180)) == 0)
		b = 10000000;
	else
		b = fabs(a * tan(h->real_angle * RADIAN));
	h->current_ver_len = b / sin(h->real_angle * RADIAN);
	h->current_ver_x = start_tile_pos_x;
	h->current_ver_y = start_tile_pos_y + offsety - b;
	if (h->quadrant == 1 || h->quadrant == 4)
		h->current_ver_x = start_tile_pos_x + (TILE);
	if (h->quadrant == 3 || h->quadrant == 4)
		h->current_ver_y = start_tile_pos_y + offsety + b;
}

void	positive_angle(t_wall *h, int angle)
{
	if (angle < 90)
		h->quadrant = 1;
	else
	{
		if (angle >= 90 && angle < 180)
			h->quadrant = 4;
		else if (angle >= 180 && angle < 270)
			h->quadrant = 3;
		else
			h->quadrant = 2;
	}
}

void	negative_angle(t_wall *h, int angle)
{
	if (angle > -90)
		h->quadrant = 2;
	else
	{
		if (angle <= -90 && angle > -180)
			h->quadrant = 3;
		else if (angle <= -180 && angle > -270)
			h->quadrant = 4;
		else
			h->quadrant = 1;
	}
}

void	decide_quadrant(t_wall *h)
{
	double	angle;

	angle = fmod(h->angle + h->p_offset, 360);
	if (h->angle + h->p_offset >= 0)
		positive_angle(h, angle);
	else
		negative_angle(h, angle);
}
