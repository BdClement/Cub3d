/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:45:42 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/15 16:13:19 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_color(char position)
{
	if (position == '1')
		return (0x005A7071);
	else if (position == ' ')
		return (0x008F470B);
	else if (position == '0' || position == 'W'
		|| position == 'E' || position == 'N' || position == 'S')
		return (0x00ffffff);
	return (0);
}

// Rescale si on veut faire minimap
void	draw_tile(t_data *info, int line, int pos)
{
	int	color;
	int	i;
	int	j;

	i = 0;
	color = get_color(info->map[line][pos]);
	if (color == 0)
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

void	display_player(t_data *info)
{
	int	i;
	int	j;
	int	x_start;
	int	y_start;

	x_start = info->player.x -(PLAYER_SIZE / 2);
	y_start = info->player.y - (PLAYER_SIZE / 2);
	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			my_mlx_pixel_put(&info->img, x_start + i, y_start + j, 0x00E41E07);
			j++;
		}
		i++;
	}
}

int	display2d_map(t_data *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			draw_tile(info, i, j);
			j++;
		}
		i++;
	}
	display_player(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}

// void	display2d_map(t_data *info)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (info->map[i])
// 	{
// 		j = 0;
// 		while (info->map[i][j])
// 		{
// 			draw_tile(info, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// }
