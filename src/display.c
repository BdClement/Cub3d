/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:45:42 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/15 22:18:40 by clbernar         ###   ########.fr       */
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

int	draw(t_data *info)
{
	float	x_line;
	float	y_line;
	float	new_x;
	float	new_y;
	float	move_step;

	// Pas sur
	move_step = (info->player.walkDirection + info->player.turnDirection) * info->player.walkSpeed;
	// Wall collision a faire !
	//MAJ rotationAngle
	info->player.rotationAngle += info->player.rotateDirection * info->player.rotationSpeed;
	// MAJ nouvelle position du player
	// Calcul aussi a faire pour se deplacer a droite a gauche ?
	new_x = info->player.x + cos(info->player.rotationAngle) * move_step;
	new_y = info->player.y + sin(info->player.rotationAngle) * move_step;
	info->player.x = new_x;
	info->player.y = new_y;
	// Calcul de la ligne qui represente rotationAngle
	x_line = info->player.x + cos(info->player.rotationAngle) * 100;
	y_line = info->player.y + sin(info->player.rotationAngle) * 100;
	display2d_map(info);
	display_player(info);
	// Draw line rotation angle
	draw_line(info, info->player.x, info->player.y, x_line, y_line);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
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

// A Normer
void draw_line(t_data *data, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        my_mlx_pixel_put(&data->img, x0, y0, 0x00E41E07);

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
