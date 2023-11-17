/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:14:15 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/17 18:49:51 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	wall_collision_x(t_data *info, float x)
{
	if (info->map[(int)info->player.y / TILE_SIZE][(int)x / TILE_SIZE] == '1')
		return (1);
	else
		return (0);
}

int	wall_collision_y(t_data *info, float y)
{
	if (info->map[(int)y / TILE_SIZE][(int)info->player.x / TILE_SIZE] == '1')
		return (1);
	else
		return (0);
}

void	wall_collision(t_data *info, float new_x, float new_y)
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
	float	new_x;
	float	new_y;
	float	move_step;

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
