/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:09:51 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/06 17:37:19 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// This function check if the ID of the line is correct or not
int	check_id(char **line)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp(line[0], "NO", 2) || !ft_strncmp(line[0], "SO", 2))
		ret = 1;
	if (!ft_strncmp(line[0], "WE", 2) || !ft_strncmp(line[0], "EA", 2))
		ret = 1;
	if (!ft_strncmp(line[0], "F", 2) || !ft_strncmp(line[0], "C", 2))
		ret = 1;
	if (ret == 0)
		ft_printf("Error\nThe ID of the line's element is incorrect\n");
	return (ret);
}

// This function checks if the ID of the line has already been filled
// If so, the file's format is not accepted by the program
int	already_filled(char **line, t_data *info)
{
	int	ret;

	ret = 1;
	if (!ft_strncmp(line[0], "NO", 2) && info->north_texture != NULL)
		ret = 0;
	if (!ft_strncmp(line[0], "SO", 2) && info->south_texture != NULL)
		ret = 0;
	if (!ft_strncmp(line[0], "WE", 2) && info->west_texture != NULL)
		ret = 0;
	if (!ft_strncmp(line[0], "EA", 2) && info->east_texture != NULL)
		ret = 0;
	if (!ft_strncmp(line[0], "F", 2) && info->floor_color[0] != -1)
		ret = 0;
	if (!ft_strncmp(line[0], "C", 2) && info->ceiling_color[0] != -1)
		ret = 0;
	if (ret == 0)
		ft_printf("Error\nThe file contains twice the same element\n");
	return (ret);
}

// This function is called at the end of the Parsing
// to be sure the file contains all information the program needs
int	file_is_complete(t_data *info)
{
	int	ret;

	ret = 1;
	if (info->north_texture == NULL || info->south_texture == NULL)
		ret = 0;
	else if (info->east_texture == NULL || info->west_texture == NULL)
		ret = 0;
	else if (info->floor_color[0] == -1 || info->ceiling_color[0] == -1)
		ret = 0;
	if (ret == 0)
	{
		ft_printf("Error\nFile is incomplete\n");
		free_t_data(info);
	}
	return (ret);
}

// This function is the second part of Fill_data_color
// It checks that only int between 0 and 255 are allowed
// And fill data structure when everything is ok
int		fill_color(char **line, char **split, t_data *info)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!is_number(split[i]) || overflow(split[i])
			|| ft_atoi(split[i]) > 255 || ft_atoi(split[i]) < 0)
		{
			free_tab(split);
			ft_printf("Error\n");
			ft_printf("The color format should be an int between 0 and 255\n");
			return (0);
		}
		else
		{
			if (!ft_strncmp(line[0], "F", 1))
				info->floor_color[i] = ft_atoi(split[i]);
			else if (!ft_strncmp(line[0], "C", 1))
				info->ceiling_color[i] = ft_atoi(split[i]);
		}
		i++;
	}
	return (1);
}
