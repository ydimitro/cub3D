/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:42:00 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 17:21:26 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Checking that there would be a player.
That there would not be more than one player. 
And then it saves the position  and  direction in the main struct.
 */
void	check_player_direction(t_main *main)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (main->map[i] != NULL)
	{
		while (main->map[i][x] != '\0')
		{
			if (main->map[i][x] == 'N' || main->map[i][x] == 'S' || \
				main->map[i][x] == 'E' || main->map[i][x] == 'W')
			{
				if (main->p_dir != '0')
					parsing_cleaning(main, NULL, MORE_THAN_ONE_PLAYER);
				main->p_dir = main->map[i][x];
				main->p_pos_x = x;
				main->p_pos_y = i;
			}
			x++;
		}
		x = 0;
		i++;
	}
	if (main->p_dir == '0')
		parsing_cleaning(main, NULL, PLAYER_DOES_NOT_EXIST);
}

void	initialize_rectangle(t_wall *height)
{
	height->p_c[0] = height->pos_cur_x - height->move;
	height->p_c[1] = height->pos_cur_y - height->move;
	height->p_c[2] = height->pos_cur_x + height->move;
	height->p_c[3] = height->pos_cur_y - height->move;
	height->p_c[4] = height->pos_cur_x - height->move;
	height->p_c[5] = height->pos_cur_y + height->move;
	height->p_c[6] = height->pos_cur_x + height->move;
	height->p_c[7] = height->pos_cur_y + height->move;
}

void	player_rotation(t_wall *height, int offset)
{
	double	s;
	double	c;
	double	tmp_x;

	tmp_x = 0;
	if (fmod(height->angle + offset, 90) == 0 || fmod(height->angle + \
		offset, 180) == 0)
	{
		s = (int)sin((height->angle + offset) * RADIAN);
		c = (int)cos((height->angle + offset) * RADIAN);
	}
	else
	{
		s = sin((height->angle + offset) * RADIAN);
		c = cos((height->angle + offset) * RADIAN);
	}
	tmp_x = height->p_c[0];
	player_center_rotation(height, tmp_x, c, s);
}

void	draw_player(t_wall *height)
{
	initialize_rectangle(height);
	player_rotation(height, height->p_offset);
	height->p_m[0] = (height->p_c[0] + height->p_c[2]) / 2;
	height->p_m[1] = (height->p_c[1] + height->p_c[3]) / 2;
	height->p_m[2] = (height->p_c[2] + height->p_c[6]) / 2;
	height->p_m[3] = (height->p_c[3] + height->p_c[7]) / 2;
	height->p_m[6] = (height->p_c[4] + height->p_c[6]) / 2;
	height->p_m[7] = (height->p_c[5] + height->p_c[7]) / 2;
	height->p_m[4] = (height->p_c[0] + height->p_c[4]) / 2;
	height->p_m[5] = (height->p_c[1] + height->p_c[5]) / 2;
}
