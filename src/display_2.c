/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:15:28 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/29 14:21:41 by clbernar         ###   ########.fr       */
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

int	get_color_hexa(int *color)
{
	int	color_hexa;
	int	alpha;

	alpha = 0x00;
	color_hexa = 0;
	color_hexa = (alpha << 24) | (color[0] << 16) | (color[1] << 8) | color[2];
	return (color_hexa);
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
			my_mlx_pixel_put(&info->img, ((pos * TILE_SIZE) + j)
				* SCALE_MINIMAP,
				((line * TILE_SIZE) + i) * SCALE_MINIMAP, color);
			j++;
		}
		i ++;
	}
}

void	display_per_ray(t_data *info, int x)
{
	int		y;
	double	start;
	double	end;

	y = 0;
	start = (info->win_height / 2) - (info->rays[x].wall_height / 2);
	end = start + info->rays[x].wall_height;
	while (y < info->win_height)
	{
		if (y < start)
			my_mlx_pixel_put(&info->img, x, y,
				get_color_hexa(info->ceiling_color));
		else if (y >= end)
			my_mlx_pixel_put(&info->img, x, y,
				get_color_hexa(info->floor_color));
		else
			draw_texture(info, x, y);
		y++;
	}
}

void	display_walls(t_data *info)
{
	int		i;
	double	d_player_to_plane;

	i = 0;
	while (i < info->nb_rays)
	{
		d_player_to_plane = (info->win_width / 2) / tan(FOV / 2);
		info->rays[i].wall_height = (TILE_SIZE
				/ info->rays[i].distance_from_player) * d_player_to_plane;
		display_per_ray(info, i);
		i++;
	}
}

// void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
// {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = (x0 < x1) ? 1 : -1;
//     int sy = (y0 < y1) ? 1 : -1;
//     int err = dx - dy;

//     while (1)
//     {
//         my_mlx_pixel_put(&data->img, x0, y0, color);

//         if (x0 == x1 && y0 == y1)
//             break;

//         int e2 = 2 * err;
//         if (e2 > -dy)
//         {
//             err = err - dy;
//             x0 = x0 + sx;
//         }

//         if (e2 < dx)
//         {
//             err = err + dx;
//             y0 = y0 + sy;
//         }
//     }
// }
