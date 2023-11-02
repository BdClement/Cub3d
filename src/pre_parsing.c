/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:50:49 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/02 19:23:36 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
