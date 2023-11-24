/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:45:42 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/24 19:19:12 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	draw(t_data *info)
{
	move_player(info);
	display2d_map(info);
	display_player(info);
	display_rotation_angle_line(info);
	raycasting(info);
	// display_walls(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	img_swap(info);
	return (0);
}

void	img_swap(t_data *info)
{
	t_imge	tmp;

	// tmp = info->img.img;
	// info->img.img = info->img.img2;
	// info->img.img2 = tmp;
	// tmp = info->img.addr;
	// info->img.addr = info->img.addr2;
	// info->img.addr2 = tmp;
	//printf("[addr1: %s, addr2: %s]\n", info->img.addr, info->img.addr2);
	tmp = info->img;
	info->img = info->img2;
	info->img2 = tmp;
	// printf("[img.swap: %d]\n", info->img.swap);
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

void	display_rotation_angle_line(t_data *info)
{
	float	x_line;
	float	y_line;

	x_line = info->player.x + cos(info->player.rotationAngle) * 100;
	y_line = info->player.y + sin(info->player.rotationAngle) * 100;
	draw_line(info, info->player.x, info->player.y, x_line, y_line, 0x00E41E07);
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
