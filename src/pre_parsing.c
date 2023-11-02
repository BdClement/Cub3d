/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:56:12 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/02 17:32:27 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	ft_printf("L'argument fourni n'est pas au format adequat\n");
	return (0);
}
