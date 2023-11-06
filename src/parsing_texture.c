/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:06:06 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/03 19:57:15 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_already_filled(char **line, t_data *info)
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
	// TESTER F ET C
	if (ret == 0)
		ft_printf("The file contains twice the same element\n");
	return (ret);
}

int	fill_data_ok(char **line, t_data *info)
{
	if (!check_already_filled(line, info))
		return (0);
	if (!ft_strncmp(line[0], "NO", 2))
		info->north_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "SO", 2))
		info->south_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "WE", 2))
		info->west_texture = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "EA", 2))
		info->east_texture = ft_strdup(line[1]);
	return (1);
}

// This function receives the line and the structure that needs
// to be filled with the information contained by the line
// If the line has 2 elements and an ID format ok, it sends it to
// ...
int	parsing_texture_line_ok(char **line, t_data *info)
{
	(void)info;
	if (get_len_tab(line) != 2 || ft_strlen(line[0]) > 2 || !fill_data_ok(line, info))
	{
		// Message d'erreur
		free_t_data(info);
		free_tab(line);
		return (0);
	}


	// Quelque chose a traiter
	return (1);
	// A faire !
			// {
			// 	free_t_data(info);
			// 	free_tab(split);
			// 	return (0);
			// }
}

// This function checks all le line of the file until the map
// If the line checked is not empty and it sends it to
// the function parsing_texture_line_ok
int	parsing_texture(char **file, t_data *info)
{
	int		i;
	char	**split;

	i = 0;
	split = NULL;
	while (file[i])
	{
		split = ft_split(file[i], ' ');
		// display_tab(split);// Test
		// Ligne avec quelque chose a traiter
		if (split != NULL && split[0] != NULL && !is_empty_line(split[0]))
		{
			if (ft_isdigit(split[0][0])) // Arrive a la map
			{
				free_tab(split);
				break ;
			}
			else if (!parsing_texture_line_ok(split, info))
				return (0);
		}
		// else
		// 	ft_printf(" La ligne %d fu fichier est vide\n", i + 1);// Test
		free_tab(split);
		i++;
	}
	// Checker si il manque quelque chose !
	return (1);
}

