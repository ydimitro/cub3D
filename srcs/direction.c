/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:21:56 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 23:21:56 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_player_start(t_data *data, char orientation, int x, int y)
{
	data->player.x = x;
	data->player.y = y;
	if (ft_strcmp(&orientation, "NO") == 1)
		data->player_dir = 90.0;
	else if (ft_strcmp(&orientation, "EA") == 1)
		data->player_dir = 0.0;
	else if (ft_strcmp(&orientation, "SO") == 1)
		data->player_dir = 270.0;
	else if (ft_strcmp(&orientation, "WE") == 1)
		data->player_dir = 180.0;
	return (0);
}
