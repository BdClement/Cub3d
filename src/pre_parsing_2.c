/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:35:35 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/29 14:39:00 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks if the file exist and if it's not a directory
void	is_existing_file(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
	{
		printf("%s is a directory.\n", str);
		if (close(fd) < 0)
			exit(EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_RDONLY, S_IRUSR);
	if (fd == -1)
	{
		printf("%s doesn't exist or doesn't have the right permissions.\n", str);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (close(fd) < 0)
			exit(EXIT_FAILURE);
	}
}

int	get_len_max(char **map)
{
	int	max_len;
	int	i;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(map[i]);
		i++;
	}
	return (max_len);
}

void	resize_map_loop(t_data *info, int len_max_in_tab, char **map_copy)
{
	int	i;
	int	j;
	int	len_tab;

	len_tab = get_len_tab(info->map);
	i = 0;
	while (i < len_tab)
	{
		j = 0;
		map_copy[i] = malloc(sizeof(char) * (len_max_in_tab + 1));
		if (map_copy[i] == NULL)
			return ;
		while (j < len_max_in_tab)
		{
			if (j < (int)ft_strlen(info->map[i]))
				map_copy[i][j] = info->map[i][j];
			else
				map_copy[i][j] = '1';
			j++;
		}
		map_copy[i][j] = '\0';
		i++;
	}
}

void	resize_map(t_data *info)
{
	char	**map_copy;
	int		len_max_in_tab;

	map_copy = NULL;
	len_max_in_tab = get_len_max(info->map);
	map_copy = malloc(sizeof(char *) * (get_len_tab(info->map) + 1));
	if (map_copy == NULL)
		return ;
	resize_map_loop(info, len_max_in_tab, map_copy);
	map_copy[get_len_tab(info->map)] = NULL;
	free_tab(info->map);
	info->map = map_copy;
}
