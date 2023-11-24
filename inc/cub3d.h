/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:27:08 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/24 19:27:12 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line_bonus.h"
# include "../libft/inc/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <errno.h>
# include <math.h>
# include <limits.h>

# define VALID_CHARS " 01NSWE"

// A definir comme on le souhaite ?
# define WINDOW_WIDTH 2304
# define WINDOW_HEIGHT 896

# define TILE_SIZE 64
# define PLAYER_SIZE 10

// * DeltaTime pour la fluidite ?
# define FOV 60 * (M_PI / 180)
# define NB_RAYS WINDOW_WIDTH // ??

# define FRONT 119
# define BACK 115
# define LEFT 97
# define RIGHT 100
# define R_LEFT 65361
# define R_RIGHT 65363

typedef struct s_ray{
	float	angle;
	int		is_facing_up;
	int		is_facing_right;
	float	x_intersect;
	float	y_intersect;
	float	xstep;
	float	ystep;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance_from_player;
	float	horiz_hit_x;
	float	horiz_hit_y;
	float	horiz_distance;
	float	vert_hit_x;
	float	vert_hit_y;
	float	vert_distance;
}			t_ray;

typedef struct s_player{
	float	x;
	float	y;
	int		turnDirection;// -1 left 1 right
	int		walkDirection;// -1 back 1 front
	int		rotateDirection;// -1 r_left 1 r_right
	float	rotationAngle;
	float	walkSpeed;//?
	float	rotationSpeed;
}			t_player;

typedef struct s_imge {
	void	*img;
	//void	*img2;
	char	*addr;
	//char	*addr2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		swap;
}				t_imge;

typedef struct s_data{
	char		**file;
	char		**map;
	char		*north_texture;
	char		*south_texture;
	char		*east_texture;
	char		*west_texture;
	int			floor_color[3];
	int			ceiling_color[3];
	void		*mlx;
	void		*win;
	t_imge		img;
	t_imge		img2;
	t_player	player;
	t_ray		rays[NB_RAYS];
}				t_data;

/********************* 0.0/UTILS ********************************/

// utils_1.c @Clement

void	display_tab(char **tab); // TEST

void	free_tab(char **tab);

int		get_len_tab(char **tab);

int		is_empty_line(char *str);

int		overflow(const char *nptr);

// utils_2.c @Clement

int		is_number(char *str);

int		comas_nb(char *str);

/********************** 0.1/INITIALISATION ***********************/

// init_struct.c @Clement

void	init_t_data(t_data *info);

void	init_t_player(t_data *info);

/********************** 0.2/CLEAR ***********************/

// clear.c @Clement

void	free_t_data(t_data *info);

int		clear(t_data *info);

/*********************PRE-PARSING*****************************/

/********************* 1.0/PRE-PARSING *****************************/

// pre_parsing_1.c @Clement @Bastien

void	format_cub_ok(char *arg);

void	parsing_is_ok(char *arg, t_data *info);

char	**get_file_content(char *arg);

int		get_file_nb_line(char *arg);

int		last_4_chars(char *arg);

/********************* 2.0/PRE-PARSING *****************************/

void	is_existing_file(char *str);

void	resize_map(t_data *info);

int		get_len_max(char **map);

/********************* PARSING ********************************/

/********************* 1.1/PARSING ********************************/

// parsing_texture_1.c @Clement

void	fill_color(char **color, char **line, t_data *info);

void	fill_data_color(char **line, t_data *info);

void	line_format_ok(char **line, t_data *info);

void	parsing_texture(char **line, t_data *info);

void	parsing(t_data *info);

// parsing_texture_2.c @Clement

void	check_id(char **line, t_data *info);

void	already_filled(char **line, t_data *info);

void	file_is_complete(char **file, t_data *info);

// parsing_map_1.c @Bastien

void	parsing_map(t_data *info, int j);

void	fill_in_map(t_data *info, int j);

void	map_is_not_last(t_data *info);

void	error_map_is_not_last(t_data *info, char *str);

void	is_incorrect_char(t_data *info);

// parsing_map_2.c @Bastien

int		check_incorrect(char *str, char *check);

void	is_player(t_data *info);

int		get_occurence(t_data *info, int line);

void	map_is_open(t_data *info);

void	check_left(t_data *info, int line, int position);

// parsing_map_3.c @Bastien

void	check_right(t_data *info, int line, int position);

void	check_up(t_data *info, int line, int position);

void	check_down(t_data *info, int line, int position);

void	get_player_position_and_direction(t_data *info, int x, int y);

/********************* WINDOW ********************************/

// window.c

void	init_window(t_data *info);

void	clear_window(t_data *info);

void	my_mlx_pixel_put(t_imge *image, int x, int y, int color);

int		key_press(int keycode, t_data *info);

/********************* DISPLAY ********************************/

// display_1.c
int		draw(t_data *info);

void	img_swap(t_data *info);

void	display_player(t_data *info);

void	display_rotation_angle_line(t_data *info);

void	display2d_map(t_data *info);

// display_2.c
int		get_color(char position);

void	draw_tile(t_data *info, int line, int pos);

void	draw_line(t_data *data, int x0, int y0, int x1, int y1, int color);

void	display_per_ray(t_data *info, int ray_index, float wall_height);

void	display_walls(t_data *info);

/********************* MOVE ********************************/
// move.c

int		intersect_collision(t_data *info, int i, float x, float y);

void	wall_collision(t_data *info, float new_x, float new_y);

int		wall_collision_x(t_data *info, float x);

int		wall_collision_y(t_data *info, float y);

void	move_player(t_data *info);

/********************* RAYCASTING ********************************/

// rays.c

void	raycasting(t_data *info);

void	set_ray(t_data *info, int i);

float	get_distance(t_data *info, float x, float y);

float	normalize_angle(float angle);

void	get_distance_from_player(t_data *info, int i);

// horizontal.c

void	find_first_horiz_intersect(t_data *info, int i);

void	find_horiz_delta(t_data *info, int i);

void	find_horiz_wall_hit(t_data *info, int i);

void	get_horizontal_distance(t_data *info, int i);

// vertical.c

void	find_first_vert_intersect(t_data *info, int i);

void	find_vert_delta(t_data *info, int i);

void	find_vert_wall_hit(t_data *info, int i, int is_left);

void	get_vertical_distance(t_data *info, int i);

#endif
