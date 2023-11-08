/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:15:13 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/08 14:15:51 by clbernar         ###   ########.fr       */
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
