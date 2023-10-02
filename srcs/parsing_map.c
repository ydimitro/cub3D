/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:38:23 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 17:43:02 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Checking the area on the right of the space.
	111 <--- possible to be 0 or 1
	1 1 <--- can only be 1
	111 <--- possible to be 0 or 1
 */
int	check_right(t_main *main, int x, int y, int x_r)
{
	int	y_up;
	int	y_d;

	y_up = y + 1;
	y_d = y - 1;
	if (y != 0 && x_r < (int)ft_strlen(main->map[y_d]) && \
	(main->map[y_d][x_r] == '0' || main->map[y_d][x_r] == main->p_dir))
	{
		if (main->map[y_d][x] != '1')
			return (1);
		else if (x_r < (int)ft_strlen(main->map[y]) && main->map[y][x_r] != '1')
			return (1);
	}
	if (x_r < (int)ft_strlen(main->map[y]) && \
		(main->map[y][x_r] == '0' || main->map[y][x_r] == main->p_dir))
		return (1);
	if (y_up < main->height && (x_r < (int)ft_strlen(main->map[y_up])) && \
		(main->map[y_up][x_r] == '0' || main->map[y_up][x_r] == main->p_dir))
	{
		if (main->map[y_up][x] != '1')
			return (1);
		else if (x_r < (int)ft_strlen(main->map[y]) && main->map[y][x_r] != '1')
			return (1);
	}
	return (0);
}

/*
Checking the middle of around the space if
	the grid does not contain 0 or player directions.
	can be only one
		|
 	   111
	   1 1
	   111
		|
	can be only one	
 */
int	check_middle(t_main *main, int x, int y)
{
	int	y_up;
	int	y_down;

	y_up = y + 1;
	y_down = y - 1;
	if (y != 0 && x < (int)ft_strlen(main->map[y_down]) && \
		(main->map[y_down][x] == '0' || main->map[y_down][x] == main->p_dir))
		return (1);
	if (main->map[y][x] == '0' || main->map[y][x] == main->p_dir)
		return (1);
	if (y_up < main->height && x < (int)ft_strlen(main->map[y_up]) && \
		(main->map[y_up][x] == '0' || main->map[y_up][x] == main->p_dir))
		return (1);
	return (0);
}

/*
Checking if the spaces to the left of the spaces are valid.
	can be 0 1 or space -->111
	can be 1 or space	-->1 1
	can be 0 1 or space	-->111
 */
int	check_left(t_main *main, int x, int y, int x_l)
{
	int	y_d;
	int	y_up;

	y_d = y - 1;
	y_up = y + 1;
	if (y != 0 && x != 0 && x_l < (int)ft_strlen(main->map[y_d]) && \
									main->map[y_d][x_l] == '0')
	{
		if (x < (int)ft_strlen(main->map[y_d]) && main->map[y_d][x] != '1')
			return (1);
		if (main->map[y][x_l] != '1')
			return (1);
	}
	if (x != 0 && x_l < (int)ft_strlen(main->map[y]) && \
		(main->map[y][x_l] == '0' || main->map[y][x_l] == main->p_dir))
		return (1);
	if (x != 0 && (y_up < main->height) && \
		x_l < (int)ft_strlen(main->map[y_up]) && main->map[y_up][x_l] == '0')
	{
		if (main->map[y][x_l] != '1')
			return (1);
		else if (main->map[y_up][x] != '1')
			return (1);
	}
	return (0);
}

/*
Taking care of checking around of each cell 
that is empty if nearby cells are empty too.
 */
void	check_spaces(t_main *main, int x, int y)
{
	while (y < main->height)
	{
		while (x < (int)ft_strlen(main->map[y]) && main->map[y][x] != '\0')
		{
			if (main->map[y][x] != '\0' && main->map[y][x] == ' ')
			{
				main->map[y][x] = '+';
				if (check_right(main, x, y, x + 1) == 1)
					parsing_cleaning(main, NULL, MAP_IS_NOT_CLOSED);
				if (check_middle(main, x, y) == 1)
					parsing_cleaning(main, NULL, MAP_IS_NOT_CLOSED);
				if (check_left(main, x, y, x - 1) == 1)
					parsing_cleaning(main, NULL, MAP_IS_NOT_CLOSED);
			}
			if (x + 3 < (int)ft_strlen(main->map[y]) && \
									main->map[y][x + 3] == ' ')
				x += 3;
			else
				x++;
		}
		x = 0;
		y++;
	}
}
