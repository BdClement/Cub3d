/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:31:36 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/10 15:32:49 by bmirlico         ###   ########.fr       */
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
