/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:45:42 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/14 19:55:08 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Rescale si on veut faire minimap
void	draw_tile(t_data *info, int line, int pos)
{
	int	color;
	int	i;
	int	j;

	i = 0;
	if (info->map[line][pos] == '1')
		color = 0x00ffffff;
	else if (info->map[line][pos] == ' ')
		color = 0x00266adb;
	else
		return ;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			my_mlx_pixel_put(&info->img, (pos * TILE_SIZE) + j, (line * TILE_SIZE) + i, color);
			j++;
		}
		i ++;
	}
}

void	display2d_map(t_data	*info)
{
	int	i;
	int	j;

	i = 0;
	// draw_tile(info, 1, 14);
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			draw_tile(info, i, j);
			j++;
			// ft_printf("%d\n", j);
		}
		i++;
		// ft_printf("%d\n", i);
	}
}
