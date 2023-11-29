/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:58:31 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/29 12:25:37 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	find_first_vert_intersect(t_data *info, int i)
{
	info->rays[i].x_intersect = floor(info->player.x / TILE_SIZE) * TILE_SIZE;
	if (info->rays[i].is_facing_right)
		info->rays[i].x_intersect += TILE_SIZE;
	info->rays[i].y_intersect = ((info->rays[i].x_intersect - info->player.x)
			* tan(info->rays[i].angle)) + info->player.y;
	if (!(info->rays[i].y_intersect >= 0
			&& info->rays[i].y_intersect < info->win_height))
		info->rays[i].vert_distance = (double)INT_MAX;
}

void	find_vert_delta(t_data *info, int i)
{
	info->rays[i].ystep = TILE_SIZE * tan(info->rays[i].angle);
	if (info->rays[i].is_facing_up && info->rays[i].ystep > 0)
		info->rays[i].ystep *= -1;
	else if ((!info->rays[i].is_facing_up && info->rays[i].ystep < 0))
		info->rays[i].ystep *= -1;
	if (info->rays[i].is_facing_right)
		info->rays[i].xstep = TILE_SIZE;
	else
		info->rays[i].xstep = -TILE_SIZE;
}

void	find_vert_wall_hit(t_data *info, int i, int is_left)
{
	while ((info->rays[i].x_intersect >= 0
			&& info->rays[i].x_intersect <= info->win_width)
		&& (info->rays[i].y_intersect >= 0
			&& info->rays[i].y_intersect <= info->win_height))
	{
		if (intersect_collision(info, i, info->rays[i].x_intersect - is_left
				, info->rays[i].y_intersect))
		{
			info->rays[i].vert_hit_x = info->rays[i].x_intersect;
			info->rays[i].vert_hit_y = info->rays[i].y_intersect;
			break ;
		}
		info->rays[i].x_intersect += info->rays[i].xstep;
		info->rays[i].y_intersect += info->rays[i].ystep;
	}
}

void	get_vertical_distance(t_data *info, int i)
{
	int		is_left;

	if (info->rays[i].is_facing_right)
		is_left = 0;
	else
		is_left = 1;
	find_first_vert_intersect(info, i);
	if (info->rays[i].vert_distance != (double)INT_MAX)
	{
		find_vert_delta(info, i);
		find_vert_wall_hit(info, i, is_left);
	}
	if (intersect_collision(info, i, info->rays[i].x_intersect - is_left
			, info->rays[i].y_intersect))
		info->rays[i].vert_distance = get_distance(info,
				info->rays[i].x_intersect, info->rays[i].y_intersect);
	else
		info->rays[i].vert_distance = (double)INT_MAX;
}
