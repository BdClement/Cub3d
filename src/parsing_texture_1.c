/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:06:06 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/08 14:38:25 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function is the second part of Fill_data_color
// It checks that only int between 0 and 255 are allowed
// And fill data structure when everything is ok
void	fill_color(char **color, char **line, char **file, t_data *info)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!is_number(color[i]) || overflow(color[i])
			|| ft_atoi(color[i]) > 255 || ft_atoi(color[i]) < 0)
		{
			free_tab(color);
			free_tab(file);
			free_tab(line);
			free_t_data(info);
			ft_printf("Error.\n");
			ft_printf("The color format should be an int between 0 and 255.\n");
			exit(EXIT_FAILURE);
		}
		if (!ft_strncmp(line[0], "F", 1))
			info->floor_color[i] = ft_atoi(color[i]);
		else if (!ft_strncmp(line[0], "C", 1))
			info->ceiling_color[i] = ft_atoi(color[i]);
		i++;
	}
	free_tab(color);
}

// This function checks the color format. If ok, it sends it to
// the function fill_color which will do more parsing test before
// fill data structure
// ,,
void	fill_data_color(char **file, char **line, t_data *info)
{
	char	**color;
	int		i;

	i = 0;
	color = NULL;
	color = ft_split(line[1], ',');
	if (get_len_tab(color) != 3 || comas_nb(line[1]) != 2)
	{
		free_tab(color);
		free_tab(file);
		free_tab(line);
		free_t_data(info);
		ft_printf("Error.\nColor format is incorrect.\n");
		exit(EXIT_FAILURE);
	}
	fill_color(color, line, file, info);
}

// This function checks if a line contains 2 elements
// If not, the line's format is incorrect
void	line_format_ok(char **file, char **line, t_data *info)
{
	if (get_len_tab(line) != 2)
	{
		ft_printf("Error.\n");
		ft_printf("A line only requires element's ID and its inforations.\n");
		free_t_data(info);
		free_tab(line);
		free_tab(file);
		exit(EXIT_FAILURE);
	}
}

// This function receives the line and the structure that needs
// to be filled with the information contained by the line
// If the line's format is ok, isn't alredady present and has a correct ID
// It fills the structure whith the informations the program needs
void	parsing_texture(char **file, char **line, t_data *info)
{
	line_format_ok(file, line, info);
	check_id(file, line, info);
	already_filled(file, line, info);
	if (!ft_strncmp(line[0], "NO", 2))
		info->north_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "SO", 2))
		info->south_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "WE", 2))
		info->west_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "EA", 2))
		info->east_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "F", 1))
		fill_data_color(file, line, info);
	if (!ft_strncmp(line[0], "C", 1))
		fill_data_color(file, line, info);
}

// This function checks all le line of the file until the map
// If the line checked is not empty and it sends it to be parsed
void	parsing(char **file, t_data *info)
{
	int		i;
	int		texture_parsed;
	char	**split;

	i = 0;
	texture_parsed = 0;
	split = NULL;
	while (file[i] && file[i][0] != '\0')
	{
		if (file[i][ft_strlen(file[i]) - 1] == '\n')
			file[i][ft_strlen(file[i]) - 1] = '\0';
		split = ft_split(file[i], ' ');
		if (split != NULL && split[0] != NULL && !is_empty_line(split[0]))
		{
			if (texture_parsed++ == 6)
			{
				free_tab(split);
				break ;
			}
			parsing_texture(file, split, info);
		}
		free_tab(split);
		i++;
	}
	//Fonction parsing map qui prend i en argument
}
