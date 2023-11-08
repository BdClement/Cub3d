/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:09:51 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/08 14:15:47 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function check if the ID of the line is correct or not
void	check_id(char **file, char **line, t_data *info)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp(line[0], "NO", 2) || !ft_strncmp(line[0], "SO", 2))
		ret = 1;
	else if (!ft_strncmp(line[0], "WE", 2) || !ft_strncmp(line[0], "EA", 2))
		ret = 1;
	else if (!ft_strncmp(line[0], "F", 2) || !ft_strncmp(line[0], "C", 2))
		ret = 1;
	if (ret == 0 || ft_strlen(line[0]) > 2)
	{
		ft_printf("Error.\nThe ID of the line's element is incorrect.\n");
		free_tab(file);
		free_tab(line);
		free_t_data(info);
		exit(EXIT_FAILURE);
	}
}

// This function checks if the ID of the line has already been filled
// If so, the file's format is not accepted by the program
void	already_filled(char **file, char **line, t_data *info)
{
	int	ret;

	ret = 1;
	if (!ft_strncmp(line[0], "NO", 2) && info->north_texture != NULL)
		ret = 0;
	else if (!ft_strncmp(line[0], "SO", 2) && info->south_texture != NULL)
		ret = 0;
	else if (!ft_strncmp(line[0], "WE", 2) && info->west_texture != NULL)
		ret = 0;
	else if (!ft_strncmp(line[0], "EA", 2) && info->east_texture != NULL)
		ret = 0;
	else if (!ft_strncmp(line[0], "F", 2) && info->floor_color[0] != -1)
		ret = 0;
	else if (!ft_strncmp(line[0], "C", 2) && info->ceiling_color[0] != -1)
		ret = 0;
	if (ret == 0)
	{
		ft_printf("Error.\nThe file contains twice the same element.\n");
		free_tab(file);
		free_tab(line);
		free_t_data(info);
		exit(EXIT_FAILURE);
	}
}

// This function is called at the end of the Parsing
// to be sure the file contains all information the program needs
void	file_is_complete(char **file, t_data *info)
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
		ft_printf("Error.\nFile is incomplete.\n");
		free_t_data(info);
		free_tab(file);
		exit(EXIT_FAILURE);
	}
}
