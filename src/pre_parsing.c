/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:50:49 by clbernar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/02 19:32:35 by bmirlico         ###   ########.fr       */
=======
/*   Updated: 2023/11/02 19:23:36 by clbernar         ###   ########.fr       */
>>>>>>> origin/Clement
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*************PARTIE CLEMENT*********************/

int	parsing_is_ok(char *arg)
{
	if (!format_cub_ok(arg))
		return (0);
	return (1);
}

// This function checks if map format is .cub or not
int	format_cub_ok(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[0] == '.')
			break ;
		if (arg[i] == '.')
		{
			if (arg[i + 1] == 'c' && arg[i + 2] == 'u'
				&& arg[i + 3] == 'b' && arg[i + 4] == '\0')
				return (1);
		}
		i++;
	}
	ft_printf("Error.\nArgument's format is not as expected.\n");
	return (0);
}

/*************PARTIE BASTIEN*********************/

int	file_exists_or_is_a_dir(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
	{
		printf("%s is a directory.\n", str);
		if (close(fd) < 0)
			exit(EXIT_FAILURE);
		return (0);
	}
	fd = open(str, O_RDONLY, S_IRUSR);
	if (fd == -1)
	{
		printf("%s doesn't exist or doesn't have the right permissions.\n", str);
		return (0);
	}
	else
	{
		if (close(fd) < 0)
			exit(EXIT_FAILURE);
		return (1);
	}
}
