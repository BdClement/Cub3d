/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:01:44 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/14 12:41:59 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// fonction qui regroupe les fonctions de parsing ayant trait
// exclusivement de la map (not dealing with what is before map)
void	parsing_map(t_data *info, int j)
{
	fill_in_map(info, j);
	map_is_not_last(info);
	is_incorrect_char(info);
	is_player(info);
	map_is_open(info);
	// display_tab(info->map);
}

void	fill_in_map(t_data *info, int j)
{
	int	i;

	i = 0;
	info->map = malloc((sizeof(char *) * (get_len_tab(info->file) - j + 1)));
	if (!info->map)
	{
		free_tab(info->file);
		free_t_data(info);
		exit(EXIT_FAILURE);
	}
	while (info->file[j] != NULL)
	{
		if (info->file[j][ft_strlen(info->file[j]) - 1] == '\n'
			&& info->file[j][0] != '\0')
			info->file[j][ft_strlen(info->file[j]) - 1] = '\0';
		info->map[i] = ft_strdup(info->file[j]);
		i++;
		j++;
	}
	info->map[i] = NULL;
}

void	map_is_not_last(t_data *info)
{
	int	i;
	int	j;

	i = 0;
	while (ft_strlen(info->map[i]) != 0 && info->map[i] != NULL)
		i++;
	j = i;
	while (ft_strlen(info->map[i]) == 0 && info->map[i] != NULL)
		i++;
	if (info->map[i] != NULL)
	{
		if (info->map[i][0] == ' ' || info->map[i][0] == 'N'
			|| info->map[i][0] == 'S' || info->map[i][0] == 'W'
			|| info->map[i][0] == 'E' || info->map[i][0] == '0'
			|| info->map[i][0] == '1')
			printf("Error.\nThere is an empty line in the map.\n");
		else
			printf("Error.\nThe map is not placed in last position.\n");
		free_t_data(info);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (info->map[j] != NULL)
		{
			free(info->map[j]);
			info->map[j] = NULL;
			j++;
		}
	}
}

// fonction qui check s'il y des characters incorrects dans la map
// i.e des chars qui ne sont pas 0, 1, N, S, E, W ou des espaces
void	is_incorrect_char(t_data *info)
{
	int	i;

	i = 0;
	while (info->map[i] != NULL)
	{
		if (check_incorrect(info->map[i], VALID_CHARS))
		{
			free_t_data(info);
			printf("Error.\nIncorrect char(s) in map.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

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
