/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:45:42 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/27 12:27:17 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// 1111111111111111111111111111111
// 10000000000000000000000000000001
// 10110000011000000001110000000001
// 100000000000000000000000N0000001
// 1111111111101100001100000000011
// 100000100001100001110011100001
// 111011100011110110000010010001
// 100000000000000100000100000001111111
// 10000111110000010000000000000011111
// 100000000000011011101000000011
// 10000000000001000111110000001
// 100000010000010101   10000011
// 100010000000000000111100000011
// 1111 111111111111111111111111111

int	draw(t_data *info)
{
	move_player(info);
	// display2d_map(info);
	// display_player(info);
	// display_rotation_angle_line(info);
	raycasting(info);
	display_walls(info);
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
			my_mlx_pixel_put(&info->img, x_start + i, y_start + j, 0x00E41E07);
			j++;
		}
		i++;
	}
}

void	display_rotation_angle_line(t_data *info)
{
	double	x_line;
	double	y_line;

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
