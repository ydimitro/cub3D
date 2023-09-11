/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:31:10 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/10 18:21:58 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <fcntl.h> 
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

#define MAP_MAX_SIZE 1024

typedef struct s_data {
	char	**map;
	int		map_width;
	int		map_height;
}	t_data;

int manage_fd(char *filename, t_data *data);
int	is_map_valid(t_data *data);
int free_mem(t_data *data);
void data_initiziated(t_data *data);

#endif
