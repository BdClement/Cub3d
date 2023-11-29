/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:45:42 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/29 14:18:03 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	draw(t_data *info)
{
	move_player(info);
	raycasting(info);
	display_walls(info);
	display2d_map(info);
	display_player(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	img_swap(info);
	return (0);
}

void	img_swap(t_data *info)
{
	t_imge	tmp;

	tmp = info->img;
	info->img = info->img2;
	info->img2 = tmp;
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
			my_mlx_pixel_put(&info->img, (x_start + i)
				* SCALE_MINIMAP, (y_start + j) * SCALE_MINIMAP, 0x00E41E07);
			j++;
		}
		i++;
	}
}

void	display2d_map(t_data *info)
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
}
