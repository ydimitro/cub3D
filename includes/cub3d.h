/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:31:10 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/19 04:35:06 by tgomes-l         ###   ########.fr       */
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


typedef struct s_ray {
	double ray_dir_x;
	double ray_dir_y;
	int map_x;
	int map_y;
	double side_dist_x;
	double side_dist_y;
	double delta_dist_x;
	double delta_dist_y;
	double perp_wall_dist;
	int step_x;
	int step_y;
	int hit;
	int side;
}	t_ray;

typedef struct s_texture {
	// For now, let's just consider a simple wall texture
	void *img;
	char	*addr;
	int width;
	int height;
	int bpp;
	int	 line_length;
	int	 endian;
	int sl;
	int end;
	int *data;
}	t_texture;

typedef struct s_player {
	double x;
	double y;
	//double direction; // measured in radians, 0 is east, PI/2 is north, etc.
	double dir_x;
	double dir_y;
	double speed;
	double turn_speed;
}	t_player;

typedef struct s_data {
	char	**map;
	int		all_file;
	int		map_width;
	int		map_height;
	char	*north;//for path on file
	char	*south;//for path on file
	char	*west;//for path on file
	char	*east;//for path on file
	char *ceiling_color;
    char *floor_color;

	void	*mlx_ptr;	   // MLX instance
	void	*win_ptr;	   // Window pointer
	void	*img_ptr;	   // Image
	char	*img_data;	  // Image data
	int	 bits_per_pixel;
	int	 size_line;
	int	 endian;

	t_player	player;
	float		player_x;
	float		player_y;
	float		player_dir; //in degrees

	t_ray ray;
	int screen_width;
	int screen_height;
	t_texture wall_texture;

	t_texture north_tex;
	t_texture south_tex;
	t_texture east_tex;
	t_texture west_tex;
}	t_data;

/*
typedef struct s_item {
	float x, y;
	int type;
	int picked_up;  // 0 for not picked up, 1 for picked up
} t_item;

typedef struct s_enemy {
	float x, y;
	int type;
	int health;
	int state; // 0 for idle, 1 for moving, 2 for attacking, etc.
} t_enemy;
*/

int		manage_fd(char *filename, t_data *data);
int		is_map_valid(t_data *data);
int		free_mem(t_data *data);
void	data_initiziated(t_data *data, int map_size);
//void get_textures(int row, char *line, t_data *data);
// int parsing_tex(char *line);
int get_elements(char *line, t_data *data);
int ft_isspace(int c) ;
int	parse_texture(char *line, t_data *data);
int get_map(char *line, t_data *data);

#endif
