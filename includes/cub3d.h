/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:31:10 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/17 19:34:49 by tgomes-l         ###   ########.fr       */
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
// # include "mlx/mlx.h"

#define MAP_MAX_SIZE 1024

# define KEY_ESC			53
# define KEY_Q				12
//Move keys
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_W_LOW			119
# define KEY_A_LOW			97
# define KEY_S_LOW			115
# define KEY_D_LOW			100
//Arrows keys
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124


typedef struct s_data {
	char	**map;
	int		map_width;
	int		map_height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int 	ceiling_r;
	int 	ceiling_g;
	int 	ceiling_b;
	int		floor_r;
	int		floor_g;
	int		floor_b;
}	t_data;

int manage_fd(char *filename, t_data *data);
int	is_map_valid(t_data *data);
int free_mem(t_data *data);
void data_initiziated(t_data *data, int map_size);


#endif
