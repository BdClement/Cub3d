/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 02:29:37 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/17 14:41:02 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// sous-fonction qui check si une ligne de la map contient
// un char incorrect
int	check_incorrect(char *str, char *check)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != '\0')
	{
		j = 0;
		count = 0;
		while (check[j] != '\0')
		{
			if (str[i] == check[j])
				count++;
			j++;
		}
		if (count == 0)
			return (1);
		i++;
	}
	return (0);
}

// fonction qui check le nb de players présents sur la map
void	is_player(t_data *info)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (info->map[i] != NULL)
	{
		ret += get_occurence(info, i);
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
int	get_occurence(t_data *info, int line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (info->map[line][i] != '\0')
	{
		if (info->map[line][i] == 'N' || info->map[line][i] == 'S'
			|| info->map[line][i] == 'W' || info->map[line][i] == 'E')
		{
			get_player_position_and_direction(info, i, line);
			count++;
		}
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
