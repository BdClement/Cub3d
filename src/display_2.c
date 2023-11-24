/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:15:28 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/24 17:15:31 by clbernar         ###   ########.fr       */
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
			my_mlx_pixel_put(&info->img, (pos * TILE_SIZE) + j,
				(line * TILE_SIZE) + i, color);
			j++;
		}
		i ++;
	}
}

void	display_per_ray(t_data *info, int x, float wall_height)
{
	int		y;
	float	start;
	float	end;

	y = 0;
	start = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	end = start + wall_height;
	// printf("start %2f  end %2f\n", start, end);
	while (y < WINDOW_HEIGHT)
	{
		if (y >= start && y < end)
			my_mlx_pixel_put(&info->img, x, y, 0x00EA891B);
		else
			my_mlx_pixel_put(&info->img, x, y, 0x00432503);
		y++;
	}
}

void	display_walls(t_data *info)
{
	int		i;
	float	d_player_to_plane;
	float	wall_height;

	i = 0;
	while (i < NB_RAYS)
	{
		// calcul de la distance du joueur au plan de projection
		d_player_to_plane = (WINDOW_WIDTH / 2) / tan(FOV / 2);
		// calcul de la taille du mur
		wall_height = (TILE_SIZE / info->rays[i].distance_from_player) * d_player_to_plane;
		display_per_ray(info, i, wall_height);
		i++;
	}
}

void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        my_mlx_pixel_put(&data->img, x0, y0, color);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err = err - dy;
            x0 = x0 + sx;
        }

        if (e2 < dx)
        {
            err = err + dx;
            y0 = y0 + sy;
        }
    }
}
