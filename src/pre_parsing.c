/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:56:12 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/02 16:44:19 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Cette fonction verifie que l'argument envoye est bien au format .ber
// This function checks if map format is .cub or not
int	map_format_ok(char *arg)
{
	int	i;
	int	format_cub;

	i = ft_strlen(arg) - 1;
	format_cub = 0;
	while (i != 0)
	{
		if (arg[i] == '.')
		{
			if (arg[i + 1] == 'c' && arg[i + 2] == 'u'
				&& arg[i + 3] == 'b')
				format_cub++;
			if (format_cub != 0)
			{
				while (arg[i])
				{
					if (arg[i] != ' ')
						return (0);
					i++;
				}
				return (1);
			}
		}
		i--;
	}
	ft_printf("L'argument fourni n'est pas au format adequat\n");
	exit(EXIT_FAILURE);
}
