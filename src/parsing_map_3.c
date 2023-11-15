/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:31:36 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/15 21:27:10 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_right(t_data *info, int line, int position)
{
	int	len;

	len = ft_strlen(info->map[line]);
	if (position == len - 1 || (position != len - 1
			&& info->map[line][position + 1] == ' '))
	{
		printf("Error.\nThe map must be surrounded by walls.\n");
		free_t_data(info);
		exit(EXIT_FAILURE);
	}
}

void	check_up(t_data *info, int line, int position)
{
	if (line == 0 || (int)ft_strlen(info->map[line - 1]) <= position)
	{
		printf("Error.\nThe map must be surrounded by walls.\n");
		free_t_data(info);
		exit(EXIT_FAILURE);
	}
	else if (info->map[line - 1][position] == ' ')
	{
		printf("Error.\nThe map must be surrounded by walls.\n");
		free_t_data(info);
		exit(EXIT_FAILURE);
	}
}

void	check_down(t_data *info, int line, int position)
{
	if (line == get_len_tab(info->map) - 1
		|| (int)ft_strlen(info->map[line + 1]) <= position)
	{
		printf("Error.\nThe map must be surrounded by walls.\n");
		free_t_data(info);
		exit(EXIT_FAILURE);
	}
	else if (info->map[line + 1][position] == ' ')
	{
		printf("Error.\nThe map must be surrounded by walls.\n");
		free_t_data(info);
		exit(EXIT_FAILURE);
	}
}

// Comprendre pourquoi ces degres la donne le comportement voulu
// N devrait etre 90 ?
void	get_rotation_angle(t_data *info, char player)
{
	if (player == 'W')
		info->player.rotationAngle = 0;
	else if (player == 'S')
		info->player.rotationAngle = 90 * (M_PI / 180);
	else if (player == 'E')
		info->player.rotationAngle = 180 * (M_PI / 180);
	else if (player == 'N')
		info->player.rotationAngle = 270 * (M_PI / 180);
}
