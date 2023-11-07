/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:06:06 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/07 18:24:28 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks the color format. If ok, it sends it to
// the function fill_color which will do more parsing test before
// fill data structure
// ,,
int	fill_data_color(char **line, t_data *info)
{
	char	**split;
	int		i;

	i = 0;
	split = NULL;
	split = ft_split(line[1], ',');
	if (get_len_tab(split) != 3)
	{
		free_tab(split);
		ft_printf("Error\nColor format is incorrect\n");
		return (0);
	}
	if (!fill_color(line, split, info))
		return (0);
	free_tab(split);
	return (1);
}

// This function checks if a line contains 2 elements
// With an ID's size not greater than 2
// If not, the line's format is incorrect
int	line_format_ok(char **line, t_data *info)
{
	if (get_len_tab(line) != 2)
	{
		ft_printf("Error\n");
		ft_printf("A line only requires an ID of element and its inforations\n");
		free_t_data(info);
		free_tab(line);
		return (0);
	}
	else if (ft_strlen(line[0]) > 2)
	{
		ft_printf("Error\nIncorrect ID\n");
		free_t_data(info);
		free_tab(line);
		return (0);
	}
	return (1);
}

// This function checks if ID's element is ok and if this element hasn't been
// read already by the parsing
// If not, it fills the data strucure with the element's information
int	fill_data_ok(char **line, t_data *info)
{
	if (!already_filled(line, info) || !check_id(line))
		return (0);
	if (!ft_strncmp(line[0], "NO", 2))
		info->north_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "SO", 2))
		info->south_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "WE", 2))
		info->west_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "EA", 2))
		info->east_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "F", 1) && !fill_data_color(line, info))
		return (0);
	if (!ft_strncmp(line[0], "C", 1) && !fill_data_color(line, info))
		return (0);
	return (1);
}

// This function receives the line and the structure that needs
// to be filled with the information contained by the line
// If the line's format is ok, it sends it to fill_data_ok
int	parsing_texture_line_ok(char **line, t_data *info)
{
	if (!line_format_ok(line, info))
		return (0);
	if (!fill_data_ok(line, info))
	{
		free_t_data(info);
		free_tab(line);
		return (0);
	}
	return (1);
}

// This function checks all le line of the file until the map
// If the line checked is not empty and it sends it to be parsed
int	parsing_texture(char **file, t_data *info)
{
	int		i;
	char	**split;

	i = 0;
	split = NULL;
	while (file[i] && file[i][0] != '\0')
	{
		if (file[i][ft_strlen(file[i]) - 1] == '\n')
			file[i][ft_strlen(file[i]) - 1] = '\0';
		split = ft_split(file[i], ' ');
		if (split != NULL && split[0] != NULL && !is_empty_line(split[0]))
		{
			if (ft_isdigit(split[0][0]))
			{
				free_tab(split);
				break ;
			}
			else if (!parsing_texture_line_ok(split, info))
				return (0);
		}
		free_tab(split);
		i++;
	}
	//ta_fontcion(i)
	return (file_is_complete(info));
}

