/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:15:13 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/27 12:33:06 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Counts the number of comas in a string
int	comas_nb(char *str)
{
	int	i;
	int	comas;

	i = 0;
	comas = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comas++;
		i++;
	}
	return (comas);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	fixing_fishbowl(t_data *info)
{
	int	i;
	int	correct_distance;

	i = 0;
	while (i < NB_RAYS)
	{
		correct_distance = cos(info->rays[i].angle - info->player.rotationAngle)
			* info->rays[i].distance_from_player;
		info->rays[i].distance_from_player = correct_distance;
		i++;
	}
}
