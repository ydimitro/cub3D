/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:33:07 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 08:33:07 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_texture(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->north_tex.img);
	mlx_destroy_image(data->mlx_ptr, data->south_tex.img);
	mlx_destroy_image(data->mlx_ptr, data->west_tex.img);
	mlx_destroy_image(data->mlx_ptr, data->east_tex.img);
}

int	free_mem(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->all_file)
	{
		free(data->map[i]);
		i++;
	}
	return (0);
}

void destroy_data(t_data *data)
{
	destroy_2d_array(data->map);
	destroy_2d_array(data->game_map);
	free(data->north);
	free(data->south);
	free(data->east);
	free(data->west);
	free(data->mlx_ptr); //do these need a specific mlx function to free
	free(data->win_ptr);
	free(data->img_ptr);
	free(data->img_data);
	free(data);
}

void destroy_2d_array(char **data_map)
{
	int i;

	i = 0;
	while (data_map[i])
	{
		free(data_map[i]);
		i++;
	}
	free(data_map);
}