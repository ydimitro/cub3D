/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:31:10 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/27 03:59:00 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <fcntl.h> 
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

#define MAP_MAX_SIZE 1024

#define SUCCESS 0
#define ERR_MULTIPLE_START 1
#define ERR_NO_START 2
#define ERR_INVALID_ARGC 3
#define ERR_INVALID_EXT 4
#define ERR_READ_FILE 5
#define ERR_PLAYER_NR 6


#define FOV (60 * (M_PI / 180))
#define DIST_TO_PROJ_PLANE (SCREEN_WIDTH / 2) / tan(FOV / 2)
#define MOVE_SPEED 60
#define ROT_SPEED 60

//KEYS
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
	double dir_x;
	double dir_y;
	int side;
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
}	t_ray;

typedef struct s_texture_calc
{
    double wall_x;
    double draw_start;
    double tex_pos;
    int tex_x;
} t_texture_calc;

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
	double dir; // measured in radians, 0 is east, PI/2 is north, etc.
	double dir_x;
	double dir_y;
	double speed;
	double turn_speed;
}	t_player;

typedef struct	s_line
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
}				t_line;

typedef struct s_data {
	char	**map;
	int		all_file;
	int		map_width;
	int		map_height;
	char	*north;//for path on file
	char	*south;//for path on file
	char	*west;//for path on file
	char	*east;//for path on file
	int ceiling_color[3];
    int floor_color[3];
	double tile_size;

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

	t_ray 		ray;
	int screen_width;
	int screen_height;
	t_texture wall_texture;

	t_texture north_tex;
	t_texture south_tex;
	t_texture east_tex;
	t_texture west_tex;
}	t_data;


int manage_fd(char *filename, t_data *data);
int	is_map_valid(t_data *data);
int free_mem(t_data *data);
void data_initiziated(t_data *data);

void cleanup_texture(t_data *data);
int free_mem(t_data *data);// Frees any dynamically allocated memory associated with the t_data structure
int set_player_start(t_data *data, char orientation, int x, int y);
void handle_error(int code);
void data_init(t_data *data);
int key_press(int keycode, t_data *data);
int manage_fd(char *filename, t_data *data); //opening and reading the game map from a file
void move_player(t_data *data, float dx, float dy);
int textures_files(t_data *data);
int textures_info(t_data *data);
int	is_map_valid(t_data *data); // Validates if the given map is correct or valid to be played
void draw_wall_slice(t_data *data, int x);
void cast_through_map(t_data *data);
void cast_single_ray(t_data *data, int x);
int ft_isspace(int c);
int	parse_texture(char *line, t_data *data);
int	parse_color(char *line, t_data *data);
void load_texture(t_data *data, t_texture *tex, char *path);
void render(t_data *data);
int		get_elements(char *line, t_data *data);
void	draw_circle(t_data *data, int x, int y);
void	draw_player(t_data *data, t_line *line);
void draw_textured_walls(t_data *data, int x, t_texture *tex);
void	draw_line(t_data *data, t_line *line);
void	set_texture(t_data *data, t_texture **tex);
void calculate_wall_x(t_data *data, t_texture_calc *tex_calc);
void calculate_texture_pos(t_data *data, t_texture_calc *tex_calc);
void	calculate_line_dir(t_data *data, t_line *line);
//void draw_rectangle(t_data *data, int x, int y, int width, int height, int color);
#endif
