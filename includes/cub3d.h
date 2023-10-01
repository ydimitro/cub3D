/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:31:10 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/27 19:16:40 by tgomes-l         ###   ########.fr       */
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
# include "../minilibx_opengl/mlx.h"

# define MAP_MAX_SIZE				1024
# define MAX_HEIGHT					1000
# define MAX_WIDTH					1000
# define MAX_MAP_LINES				100
# define SUCCESS					0
# define ERR_MULTIPLE_START			1
# define ERR_NO_START				2
# define ERR_INVALID_ARGC			3
# define ERR_INVALID_EXT			4
# define ERR_READ_FILE				5
# define ERR_PLAYER_NR				6
# define ERR_MAP_ALLOCATION_FAILED	7
# define ERR_TEXTURE_LOAD_FAILED	8
# define ERR_EMPTY_MAP				9
# define SCREEN_WIDTH				800
# define FOV						60
# define MOVE_SPEED					1
# define ROT_SPEED					60
# define KEY_ESC					53
# define KEY_Q						12
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define KEY_W_LOW					119
# define KEY_A_LOW					97
# define KEY_S_LOW					115
# define KEY_D_LOW					100
# define KEY_LEFT					123
# define KEY_RIGHT					124

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	int			side;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
}	t_ray;

typedef struct s_texture_calc
{
    double 		wall_x;
    double 		draw_start;
    double 		tex_pos;
    int 		tex_x;
	int 		tex_y;
    int 		color;
} t_texture_calc;

typedef struct s_texture
{
	void 		*img;
	char		*addr;
	int 		width;
	int 		height;
	int 		bpp;
	int	 		line_length;
	int	 		endian;
	int 		sl;
	int 		end;
	int 		*data;
}	t_texture;

typedef struct s_player
{
	double 		x;
	double 		y;
	double 		dir;
	double 		dir_x;
	double 		dir_y;
	double 		speed;
	double 		turn_speed;
}	t_player;

typedef struct s_line_params
{
    int 		dx;
    int 		dy;
    int 		sx;
    int 		sy;
    int 		err;
}               t_line_params;

typedef struct	s_line
{
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
}				t_line;

typedef struct s_data {
	char		**map;
	char 		**game_map;
	int 		game_map_size;
	size_t 		game_map_capacity;
	int 		in_map_section;
	int			all_file; // number of rows
	int			map_width;
	int			map_height;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			ceiling_color[3];
    int			floor_color[3];
	double 		tile_size;

	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*img_adr;
	char		*img_data;
	int	 		bits_per_pixel;
	int	 		size_line;
	int	 		endian;

	t_player	player;
	float		player_dir;

	t_ray 		ray;
	int 		screen_width;
	int 		screen_height;
	t_texture 	wall_texture;

	t_texture 	north_tex;
	t_texture 	south_tex;
	t_texture 	east_tex;
	t_texture 	west_tex;
	double		DIST_TO_PROJ_PLANE;
}	t_data;

//create.c
t_data *create_data();

//destroy.c
void	cleanup_texture(t_data *data);
int		free_mem(t_data *data);
void	destroy_2d_array(char **data_map);
void	destroy_data(t_data *data);

//direction.c
int		set_player_start(t_data *data, char orientation, int x, int y);

//drawing_utils_2.c
int		custom_abs(int x);
void	calc_line_dir(t_data *data, t_line *line);
void	calc_wall_x(t_data *data, t_texture_calc *texture_calc);
void	calc_deltas_and_steps(t_line *line, t_line_params *params);
int		get_wall_color(t_data *data);

//drawing_utils_texture.c
void	set_texture(t_data *data, t_texture **texture);
void	calc_texture_pos(t_data *data, t_texture_calc *texture_calc);
void	initialize_texture_variables(t_data *data, t_texture_calc *texture_calc);
void	draw_textured_walls(t_data *data, int x, t_texture *texture);
void	draw_wall_slice(t_data *data, int x);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

//drawing.c
void	draw_circle(t_data *data, int x, int y);
void	set_line_endpoints(t_data *data, t_line *line);
void	draw_player(t_data *data);
void	draw_line(t_data *data, t_line *line);

//error_handling.c
void handle_error(int code);

//init.c
void	data_init(t_data *data);
void	load_all_textures(t_data *data);

//map_check.c
int		is_map_empty(t_data *data);
int		check_valid_chars(t_data *data);
int		check_player_count(char **map);
bool	is_map_closed(t_data *data);
int		check_boundary_cells(bool visited[][MAX_WIDTH], int height, int width);

//map_get_valid.c
int		ft_isspace(int c);
int		get_map(char *line, t_data *data);
int		is_map_valid(t_data *data);

//map_parse_utils.c
int		is_valid_char(char c);
int		count_players(char **map);
void	dfs(int row, int col, t_data *data,
	bool visited[data->map_height][data->map_width]);
int		resize_game_map(t_data *data);
int		allocate_initial_map(t_data *data);

//movement.c
void	handle_movement(int keycode, t_data *data, float *dx, float *dy);
void	handle_rotation(int keycode, t_data *data);
int		key_press(int keycode, t_data *data);
void	move_player(t_data *data, float dx, float dy);

//raycasting.c
void	set_wall_distance(t_data *data);
void	cast_through_map(t_data *data);
void	cast_single_ray(t_data *data, int x);
void	set_ray_step_and_side_dist(t_data *data);

//rendering.c
void	render(t_data *data);
t_texture *ray_direction(t_data *data);

//textures_parse.c
int		get_elements( char *line, t_data *data);
int		parse_texture(char *line, t_data *data);
int		parse_color(char *line, t_data *data);

// debugging to delete after
void print_2d_array(char **map);
#endif
