/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:50:49 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/02 18:09:02 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// MESSI A VOLE LE BALLON D'OR !!!!!

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if ((!s) || (n <= 0))
		return ;
	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
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
//		HEY OH !!!!!!!
		if (arg[i] == '.')
		{
			if (arg[i + 1] == 'c' && arg[i + 2] == 'u'
				&& arg[i + 3] == 'b' && arg[i + 4] == '\0')
				return (1);
		}
		i++;
	}
	ft_printf("L'argument fourni n'est pas au format adequat\n");
	ft_printf("TEST\n");
	return (0);
}




// HAALAND LE MERITAIT TELLEMENT !!!!!
