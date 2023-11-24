/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:04:48 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/24 19:18:51 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	raycasting(t_data *info)
{
	int	i;

	i = 0;
	while (i < NB_RAYS)
	{
		set_ray(info, i);
		get_horizontal_distance(info, i);
		get_vertical_distance(info, i);
		get_distance_from_player(info, i);
		draw_line(info, info->player.x, info->player.y, info->rays[i].wall_hit_x, info->rays[i].wall_hit_y, 0x00D8BE16);
		i++;
	}
}

void	get_distance_from_player(t_data *info, int i)
{
	if (info->rays[i].vert_distance < info->rays[i].horiz_distance)
	{
		info->rays[i].wall_hit_x = info->rays[i].vert_hit_x;
		info->rays[i].wall_hit_y = info->rays[i].vert_hit_y;
		info->rays[i].distance_from_player = info->rays[i].vert_distance;
	}
	else
	{
		info->rays[i].wall_hit_x = info->rays[i].horiz_hit_x;
		info->rays[i].wall_hit_y = info->rays[i].horiz_hit_y;
		info->rays[i].distance_from_player = info->rays[i].horiz_distance;
	}
}

float	get_distance(t_data *info, float x, float y)
{
	float	distance;

	distance = sqrt(pow(x - info->player.x, 2) + pow(y - info->player.y, 2));
	return (distance);
}

void	set_ray(t_data *info, int i)
{
	if (i == 0)
	{
		info->rays[i].angle = info->player.rotationAngle - (FOV / 2);
		info->rays[i].angle = normalize_angle(info->rays[i].angle);
	}
	else
	{
		info->rays[i].angle = info->rays[i - 1].angle + (FOV / NB_RAYS);
		info->rays[i].angle = normalize_angle(info->rays[i].angle);
	}
	if (info->rays[i].angle >= 0 && info->rays[i].angle < M_PI)
		info->rays[i].is_facing_up = 0;
	else
		info->rays[i].is_facing_up = 1;
	if (info->rays[i].angle >= 90 * (M_PI / 180)
		&& info->rays[i].angle < 270 * (M_PI / 180))
		info->rays[i].is_facing_right = 0;
	else
		info->rays[i].is_facing_right = 1;
	info->rays[i].horiz_hit_x = 0;
	info->rays[i].horiz_hit_y = 0;
	info->rays[i].vert_hit_x = 0;
	info->rays[i].vert_hit_y = 0;
	info->rays[i].horiz_distance = 0;
	info->rays[i].vert_distance = 0;
}

float	normalize_angle(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}
