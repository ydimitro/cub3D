/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:00:43 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 18:11:37 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//Headers
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../minilibx_opengl/mlx.h"

//ERROR Codes
# define SPEED_TO_LITTLE		-5
# define DEFAULT_CEILING_COLOR	-4
# define DEFAULT_FLOOR_COLOR	-3
# define TILE_SIZE		 		-2
# define SCREEN_SIZE	 		-1
# define NOT_ENOUGH_ARGS 		1
# define INVALID_ARGS			2
# define WRONG_FILE_EXTENSION 	3
# define FILE_IS_NOT_THERE 		4
# define INCORECT_FILE_CONFIG	5
# define CUB_CONTAINS_TRASH		6
# define MISSING_ELEMENT_PATH	7
# define FOUND_ELEMENT_TRASH	8
# define INCORECT_COLOR_VAL		9
# define TAB_IN_MAP_FOUND		10
# define MAP_NOT_CLOSED			11
# define WRONG_INFO_IN_MAP		12
# define EMPTY_LINE_IN_MAP		13
# define MORE_THAN_ONE_PLAYER	14
# define MAP_IS_NOT_CLOSED		15
# define PLAYER_DOES_NOT_EXIST	16
# define XPM_HAS_FAILED_TO_OPEN	17

//Screen size
# define S_WIDTH 1280
# define S_HEIGHT 720

//Colors
# define B "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELL	"\033[0;33m"

//Radians
# define RADIAN 0.0174532925

//Keys
# ifdef __APPLE__
#  define LEFT_KEY	124
#  define RIGHT_KEY	123
#  define W_KEY		13
#  define S_KEY		1
#  define D_KEY		2
#  define A_KEY		0
#  define ESC_KEY	53
# elif __linux__
#  define LEFT_KEY 	97
#  define RIGHT_KEY 100
#  define W_KEY		119
#  define S_KEY		115
#  define D_KEY		100
#  define A_KEY		97
#  define ESC_KEY	65307
# endif

//Tile size
# define TILE	32

//Textures and colors
 # define D_NO "./textures/default_north.xpm"
 # define D_EA "./textures/default_east.xpm"
 # define D_SO "./textures/default_south.xpm"
 # define D_WE "./textures/default_west.xpm"
# define D_F 0xDC6400
# define D_C 0xE11E00

//wall_collisions norminette
typedef enum {
    DIRECTION_W,
    DIRECTION_S,
    DIRECTION_A,
    DIRECTION_D
} t_direction;

//wall_collisions norminette
typedef struct {
    int corner1;
    int corner2;
    int center1;
    int center2;
} t_collision_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_texture
{
	void	*img;
	char	*data;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}				t_texture;

typedef struct s_wall_texures
{
	t_texture	*texture_north;
	t_texture	*texture_south;
	t_texture	*texture_west;
	t_texture	*texture_east;
}				t_wall_tex;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_main
{
	int		file_fd;
	char	p_dir;
	char	p_pos_x;
	char	p_pos_y;
	int		p_x;
	int		p_y;
	char	*north_t;
	char	*south_t;
	char	*west_t;
	char	*east_t;
	char	**map;
	int		height;
	int		floor;
	int		ceiling;
	int		h_hit;
	int		v_hit;
}				t_main;

typedef struct s_brezenham
{
	int		decision_v;
	int		direction;
	int		delta_x;
	int		delta_y;
}				t_brez;

typedef struct s_wall
{
	t_main		*main;
	t_data		*data;
	t_vars		*vars;
	t_brez		*b;
	t_wall_tex	*wall_tex;
	int			line[4];
	int			pos_cur_x;
	int			pos_cur_y;
	int			current_tile_pos_x;
	int			current_tile_pos_y;
	double		angle;
	int			p_c[8];
	int			p_m[8];
	int			p_offset;
	int			move;
	double		f_int_x;
	double		f_int_y;
	double		current_hor_len;
	double		current_ver_len;
	double		current_hor_x;
	double		current_hor_y;
	double		current_ver_x;
	double		current_ver_y;
	bool		x_ray;
	double		horizontal_x_scaling;
	double		vertical_y_scaling;
	int			quadrant;
	double		real_angle;
	double		shortest_dist_to_wall;
	double		one_colum_increase;
	double		p_dist_from_projection_plane;
	double		tex_to_tile_ratio_x;
	double		tex_to_line_h_ratio_y;
}				t_wall;

//colors.c
void	free_color_array(char **c);
void	take_care_of_color(char *buffer, t_main *m, char id);

//destroy.c
void	destroy_wall_texures(t_wall *wall);
void	freeing_wall(t_wall *wall);
void	parsing_cleaning(t_main *main, char *arr, int err);
int		close_game(t_wall *wall);
void	clear_the_main_struct(t_main *main);

//draw_line_utils.c
void	pixel_placement_decider(t_wall *height, int x, int color);
void	draw_low_slope(t_wall *height, int color);
void	draw_high_slope(t_wall *height, int color);

//draw_line.c
void	draw_line(t_wall *height, int color);

//draw3d.c
int			my_mlx_pixel_get(t_wall *height, t_texture *texture, int x, int y);
int			get_start_row(double line_h);
t_texture	*choose_texture(t_wall *height);
void		draw_vertical_line(t_wall *height, double temp_line_h);
void		draw_3d(t_wall *height, int a, double fov);

//error_utils.c
bool	map_fragment_found(char *buffer);
bool	match_component_name(char *name);
bool	component_found(char *str);
void	find_trash(t_main *main, char *s);

//errors.c
int		first_error_messages(int err);
void	ft_exiterr(int err);
void	check_basic_errors(t_main *main, int argc, char **argv);

//init.c
void	initialize_main(t_main *main);
void	calloc_struct(t_wall *wall);
void	initialize_wall(t_wall *wall, t_main *main);
void	initialize_mlx(t_data *img, t_vars *vars);

//main.c
void	move_player(t_wall *wall, int indentifier);
int		key_hook(int keycode, t_wall *wall);
int		render(t_wall *height);
void	hooks_n_loops(t_wall *wall);

//parse_map_utils.c
void	save_map(t_main *main, char **argv, int len);
bool	check_for_map_start(char *buffer, t_main *main);
int		map_skip_space(int i, char *b, char id);
int		check_map_fragments(t_main *main, char *b, int *c);

//parsing_map.c
int		check_right(t_main *main, int x, int y, int x_r);
int		check_middle(t_main *main, int x, int y);
int		check_left(t_main *main, int x, int y, int x_l);
void	check_spaces(t_main *main, int x, int y);

//parsing_utils.c
bool	match(char *searched, char *str);
void	open_the_file(t_main *main, char **argv);
void	check_file_extension(char *filename);

//parsing.c
void	check_for_elements(char *buffer, t_main *main);
void	find_elements(t_main *main);
void	parsing(t_main *main, char **argv);

//player.c
void	check_player_direction(t_main *main);
void	initialize_rectangle(t_wall *height);
void	player_rotation(t_wall *height, int offset);
void	draw_player(t_wall *height);

//raycasing_init.c
void	first_horizontal(t_wall *height, \
	int start_tile_pos_x, int start_tile_pos_y);
void	first_vertical(t_wall *height, \
	int start_tile_pos_x, int start_tile_pos_y);
void	positive_angle(t_wall *height, int angle);
void	negative_angle(t_wall *height, int angle);
void	decide_quadrant(t_wall *height);

//raycasting_utils.c
int		check_horizontal_wall(t_wall *height);
int		check_vertical_wall(t_wall *height);
void	count_horizontal_scaling(t_wall *height);
void	count_vertical_scaling(t_wall *height);
double	calculate_dist_draw(t_wall *height, int hor_hit, int ver_hit);

//raycasting.c
void	rest_horizontal(t_wall *height, int start_tile_pos_y, int step);
void	rest_vertical(t_wall *height, int start_tile_pos_x, int step);
void	raycasting(t_wall *height, int start_tile_pos_x, int start_tile_pos_y);
void	draw_2d_rays(t_wall *height);

//texture_handling.c
void	load_texure(t_texture *t, t_wall *height, char *t_path);
char	*prepare_element_path(char *str);
void	free_splitted(char **split, char *element_name);
char	*save_element(t_main *main, char *buffer);
void	take_care_of_texure(char *buffer, t_main *main, char name);

//utils.c
void	position_offset(t_main *main, t_wall *wall);
int		check_wall(t_wall *height, int x_future, int y_future);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	player_center_rotation(t_wall *height, double tmp_x, double c, double s);
void	load_assets(t_wall *height);
int		ft_isspace(int c);
char	*trim_whitespace(char *str);

//wall_collision_utils.c
int check_center_and_corners(t_wall *height, t_collision_data *data);
int	check_position(t_wall *height);

//wall_collision.c
int		wall_colision_a(t_wall *height, int check_wall_colision);
int		wall_colision_s(t_wall *height, int check_wall_colision);
int		wall_colision_w(t_wall *height, int check_wall_colision);
int		wall_colision_d(t_wall *height, int check_wall_colision);
int		wall_colision_check(t_wall *height, int keycode);

#endif
