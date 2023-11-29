/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:04:48 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/29 15:06:11 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	raycasting(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->nb_rays)
	{
		set_ray(info, i);
		get_horizontal_distance(info, i);
		get_vertical_distance(info, i);
		get_distance_from_player(info, i);
		i++;
	}
	fixing_fishbowl(info);
}

void	get_distance_from_player(t_data *info, int i)
{
	if (info->rays[i].vert_distance < info->rays[i].horiz_distance)
	{
		info->rays[i].wall_hit_x = info->rays[i].vert_hit_x;
		info->rays[i].wall_hit_y = info->rays[i].vert_hit_y;
		info->rays[i].distance_from_player = info->rays[i].vert_distance;
		info->rays[i].hit_is_vert = 1;
	}
	else
	{
		info->rays[i].wall_hit_x = info->rays[i].horiz_hit_x;
		info->rays[i].wall_hit_y = info->rays[i].horiz_hit_y;
		info->rays[i].distance_from_player = info->rays[i].horiz_distance;
		info->rays[i].hit_is_vert = -1;
	}
}

double	get_distance(t_data *info, double x, double y)
{
	double	distance;

	distance = sqrt(pow(x - info->player.x, 2) + pow(y - info->player.y, 2));
	return (distance);
}

void	set_ray(t_data *info, int i)
{
	if (i == 0)
	{
		info->rays[i].angle = info->player.rotation_angle - (FOV / 2);
		info->rays[i].angle = normalize_angle(info->rays[i].angle);
	}
	else
	{
		info->rays[i].angle = info->rays[i - 1].angle + (FOV / info->nb_rays);
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
	init_ray(info, i);
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}
