/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 02:29:37 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/08 18:33:53 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// fonction qui check le nb de players présents sur la map
void	is_player(t_data *info)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (info->map[i] != NULL)
	{
		ret += get_occurence(info->map[i]);
		i++;
	}
	if (ret == 0 || ret > 1)
	{
		free_t_data(info);
		if (ret == 0)
			printf("Error.\nNo player in map.\n");
		else
			printf("Error.\nMore than one player in map.\n");
		exit(EXIT_FAILURE);
	}
}

// sous-fonction qui check s'il y a un joueur présent sur une ligne
int	get_occurence(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'W' || str[i] == 'E')
			count++;
		i++;
	}
	return (count);
}

// fonction qui check si la map est "ouverte" c'est-à-dire
// n'est pas entourée de murs '1'
// Attention, chaque ligne peut etre separée par des espaces
void	map_is_open(t_data *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '0' || info->map[i][j] == 'N'
			|| info->map[i][j] == 'S' || info->map[i][j] == 'W'
			|| info->map[i][j] == 'E' )
			{
				check_up(info, i, j);
				check_down(info, i, j);
				check_left(info, i, j);
				check_right(info, i, j);
			}
			j++;
		}
		i++;
	}
}

void	check_left(t_data *info, int line, int position)
{
	if (position == 0
		|| (position != 0 && info->map[line][position - 1] == ' '))
	{
		printf("Error.\nThe map must be surrounded by walls.\n");
		free_t_data(info);
		exit(EXIT_FAILURE);
	}
}

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
