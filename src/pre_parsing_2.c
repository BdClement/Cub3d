/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:35:35 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/10 15:36:06 by bmirlico         ###   ########.fr       */
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
