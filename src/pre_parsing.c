/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:50:49 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/02 19:31:12 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function checks if map format is .cub or not
// int	format_cub_ok(char *arg)
// {
// 	int	i;

// 	i = 0;
// 	while (arg[i])
// 	{
// 		if (arg[0] == '.')
// 			break ;
// 		if (arg[i] == '.')
// 		{
// 			if (arg[i + 1] == 'c' && arg[i + 2] == 'u'
// 				&& arg[i + 3] == 'b' && arg[i + 4] == '\0')
// 				return (1);
// 		}
// 		i++;
// 	}
// 	//ft_printf("L'argument fourni n'est pas au format adequat\n");
// 	return (0);
// }

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
