/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:14:15 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/24 19:30:57 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	intersect_collision(t_data *info, int i, double x, double y)
{
	(void)i;
	int	y_map;
	int	x_map;
	// Protection ne marche pas
	y_map = (int)y / TILE_SIZE;
	x_map = (int)x / TILE_SIZE;
	if (y_map >= get_len_tab(info->map) || y_map < 0|| x_map >= (int)ft_strlen(info->map[0]) || x_map < 0)
		return (0);
	if (info->map[y_map][x_map] == '1')
		return (1);
	else
		return (0);
}


int	wall_collision_x(t_data *info, double x)
{
	if (info->map[(int)info->player.y / TILE_SIZE][(int)x / TILE_SIZE] == '1')
		return (1);
	else
		return (0);
}

int	wall_collision_y(t_data *info, double y)
{
	if (info->map[(int)y / TILE_SIZE][(int)info->player.x / TILE_SIZE] == '1')
		return (1);
	else
		return (0);
}

void	wall_collision(t_data *info, double new_x, double new_y)
{
	int	x;
	int	y;

	x = (int)new_x / TILE_SIZE;
	y = (int)new_y / TILE_SIZE;
	if (!wall_collision_y(info, new_y) && !wall_collision_x(info, new_x))
	{
		info->player.x = new_x;
		info->player.y = new_y;
	}
}

void	move_player(t_data *info)
{
	double	new_x;
	double	new_y;
	double	move_step;

	move_step = (info->player.walkDirection + info->player.turnDirection)
		* info->player.walkSpeed;
	info->player.rotationAngle += info->player.rotateDirection
		* info->player.rotationSpeed;
	info->player.rotationAngle += info->player.rotateDirection
		* info->player.rotationSpeed;
	if (info->player.walkDirection != 0)
	{
		new_x = info->player.x + cos(info->player.rotationAngle) * move_step;
		new_y = info->player.y + sin(info->player.rotationAngle) * move_step;
		wall_collision(info, new_x, new_y);
	}
	else if (info->player.turnDirection != 0)
	{
		new_x = info->player.x + cos(info->player.rotationAngle + M_PI_2)
			* move_step;
		new_y = info->player.y + sin(info->player.rotationAngle + M_PI_2)
			* move_step;
		wall_collision(info, new_x, new_y);
	}
}
