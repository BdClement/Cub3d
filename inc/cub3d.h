/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:27:08 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/03 16:24:09 by clbernar         ###   ########.fr       */
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

/*********************PRE-PARSING********************************/

// pre_parsing.c

int		format_cub_ok(char *arg);
int		parsing_is_ok(char *arg);
char	**get_file_content(char *arg);
int		get_file_nb_line(char *arg);
int		file_exists_or_is_a_dir(char *str);
void	display_tab(char **tab); // TEST
void	free_tab(char **tab);

#endif
