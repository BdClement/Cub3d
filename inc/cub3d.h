/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:27:08 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/08 14:17:05 by clbernar         ###   ########.fr       */
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

typedef struct s_data{
	char	**map;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		floor_color[3];
	int		ceiling_color[3];
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
/*********************PRE-PARSING*****************************/

// pre_parsing.c
void	format_cub_ok(char *arg);
void	parsing_is_ok(char *arg, t_data *info);
char	**get_file_content(char *arg);
int		get_file_nb_line(char *arg);
void	is_existing_file(char *str);

/********************* PARSING ********************************/

// parsing_texture_1.c
void	fill_color(char **color, char **line, char **split, t_data *info);
void	fill_data_color(char **file, char **line, t_data *info);
void	line_format_ok(char **file, char **line, t_data *info);
void	parsing_texture(char **file, char **line, t_data *info);
void	parsing(char **file, t_data *info);
// parsing_texture_2.c
void	check_id(char **file, char **line, t_data *info);
void	already_filled(char **file, char **line, t_data *info);
void	file_is_complete(char **file, t_data *info);


#endif
