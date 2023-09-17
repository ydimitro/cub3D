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

void cleanup_texture(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->north_tex.img);
	mlx_destroy_image(data->mlx_ptr, data->south_tex.img);
	mlx_destroy_image(data->mlx_ptr, data->west_tex.img);
	mlx_destroy_image(data->mlx_ptr, data->east_tex.img);
}

int free_mem(t_data *data)
{
	int i = 0;
	while(i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	return(0);
}