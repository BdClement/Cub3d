/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:27:08 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/14 15:21:38 by clbernar         ###   ########.fr       */
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

# define VALID_CHARS " 01NSWE"

// A definir comme on le souhaite ?
# define WINDOW_WIDTH 2304
# define WINDOW_HEIGHT 896

# define TILE_SIZE 64

//CODE MOVE



typedef struct	s_imge {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imge;

typedef struct s_data{
	char	**file;
	char	**map;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	void	*mlx;
	void	*win;
	t_imge	img;
}				t_data;

/********************* UTILS ********************************/

// utils_1.c
void	display_tab(char **tab); // TEST

void	free_tab(char **tab);

int		get_len_tab(char **tab);

int		is_empty_line(char *str);

int		overflow(const char *nptr);

// utils_2.c

int		is_number(char *str);

int		comas_nb(char *str);

/********************** INITIALISATION ***********************/

// init_struct.c

void	init_t_data(t_data *info);

/********************** CLEAR ***********************/

// clear.c

void	free_t_data(t_data *info);

int		clear(t_data *info);
/*********************PRE-PARSING*****************************/

// pre_parsing.c

void	format_cub_ok(char *arg);

void	parsing_is_ok(char *arg, t_data *info);

char	**get_file_content(char *arg);

int		get_file_nb_line(char *arg);

void	is_existing_file(char *str);

int		last_4_chars(char *arg);

/********************* PARSING ********************************/

// parsing_texture_1.c

void	fill_color(char **color, char **line, t_data *info);

void	fill_data_color(char **line, t_data *info);

void	line_format_ok(char **line, t_data *info);

void	parsing_texture(char **line, t_data *info);

void	parsing(t_data *info);

// parsing_texture_2.c

void	check_id(char **line, t_data *info);

void	already_filled(char **line, t_data *info);

void	file_is_complete(char **file, t_data *info);

// parsing_map_1.c @Bastien

void	parsing_map(t_data *info, int j);

void	fill_in_map(t_data *info, int j);

void	map_is_not_last(t_data *info);

void	is_incorrect_char(t_data *info);

int		check_incorrect(char *str, char *check);

// void	is_empty_line(char **arg, int j);

// parsing_map_2.c @Bastien

void	is_player(t_data *info);

int		get_occurence(char *str);

void	map_is_open(t_data *info);

void	check_left(t_data *info, int line, int position);

void	check_right(t_data *info, int line, int position);

void	check_up(t_data *info, int line, int position);

void	check_down(t_data *info, int line, int position);

/********************* WINDOW ********************************/

// window.c
void	init_window(t_data *info);

void	clear_window(t_data *info);

void	my_mlx_pixel_put(t_imge *image, int x, int y, int color);
#endif
