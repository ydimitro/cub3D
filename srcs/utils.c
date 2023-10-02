/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:43:31 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 15:12:57 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"

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

int	check_wall(t_wall *height, int x_future, int y_future)
{
	int	wallx;
	int	wally;

	wallx = (x_future - TILE) / (TILE);
	wally = (y_future - TILE) / (TILE);
	if (wally >= 0 && wally < height->main->height && wallx >= 0 && \
		wallx < (int)ft_strlen(height->main->map[wally]))
	{
		if (height->main->map[wally][wallx] == '1')
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

void	player_center_rotation(t_wall *height, double tmp_x, double c, double s)
{
	tmp_x = height->p_c[0];
	height->p_c[0] = ((height->p_c[0] - height->pos_cur_x) * c - \
					(height->p_c[1] - height->pos_cur_y) * s) + height->pos_cur_x;
	height->p_c[1] = ((tmp_x - height->pos_cur_x) * s + \
					(height->p_c[1] - height->pos_cur_y) * c) + height->pos_cur_y;
	tmp_x = height->p_c[2];
	height->p_c[2] = ((height->p_c[2] - height->pos_cur_x) * c - \
					(height->p_c[3] - height->pos_cur_y) * s) + height->pos_cur_x;
	height->p_c[3] = ((tmp_x - height->pos_cur_x) * s + \
					(height->p_c[3] - height->pos_cur_y) * c) + height->pos_cur_y;
	tmp_x = height->p_c[4];
	height->p_c[4] = ((height->p_c[4] - height->pos_cur_x) * c - \
					(height->p_c[5] - height->pos_cur_y) * s) + height->pos_cur_x;
	height->p_c[5] = ((tmp_x - height->pos_cur_x) * s + \
					(height->p_c[5] - height->pos_cur_y) * c) + height->pos_cur_y;
	tmp_x = height->p_c[6];
	height->p_c[6] = ((height->p_c[6] - height->pos_cur_x) * c - \
					(height->p_c[7] - height->pos_cur_y) * s) + height->pos_cur_x;
	height->p_c[7] = ((tmp_x - height->pos_cur_x) * s + \
					(height->p_c[7] - height->pos_cur_y) * c) + height->pos_cur_y;
}

void	load_assets(t_wall *height)
{
	if (height->main->north_t != NULL)
		load_texure(height->wall_tex->texture_north, height, height->main->north_t);
	else
		load_texure(height->wall_tex->texture_north, height, D_NO);
	if (height->main->south_t != NULL)
		load_texure(height->wall_tex->texture_south, height, height->main->south_t);
	else
		load_texure(height->wall_tex->texture_south, height, D_SO);
	if (height->main->east_t != NULL)
		load_texure(height->wall_tex->texture_east, height, height->main->east_t);
	else
		load_texure(height->wall_tex->texture_east, height, D_EA);
	if (height->main->west_t != NULL)
		load_texure(height->wall_tex->texture_west, height, height->main->west_t);
	else
		load_texure(height->wall_tex->texture_west, height, D_WE);
	if (height->main->floor == -1)
		height->main->floor = D_F;
	if (height->main->ceiling == -1)
		height->main->ceiling = D_C;
}


int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

/*
Helper function to trim leading and trailing whitespaces.
*/
char *trim_whitespace(char *str)
{
    char *start;
    char *end;
    int i;
	int	j;

    while (*str && (char)ft_isspace(*str))
        str++;
    start = str;
    end = start + ft_strlen(start) - 1;
    while (end > start && ft_isspace(*end))
        end--;
    *(end + 1) = '\0';
    i = 0;
	j = 0;
    while (start[i])
    {
        if (!ft_isspace(start[i]) || (i > 0 && !ft_isspace(start[i - 1])))
            start[j++] = start[i];
        i++;
    }
    start[j] = '\0';
    return ft_strdup(start);
}
