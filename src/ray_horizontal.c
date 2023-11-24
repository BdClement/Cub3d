/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:58:15 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/24 19:13:41 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	find_first_horiz_intersect(t_data *info, int i)
{
	info->rays[i].y_intersect = floor(info->player.y / TILE_SIZE) * TILE_SIZE;
	if (!(info->rays[i].is_facing_up))
		info->rays[i].y_intersect += TILE_SIZE;
	info->rays[i].x_intersect = ((info->rays[i].y_intersect - info->player.y)
			/ tan(info->rays[i].angle)) + info->player.x;
	if (!(info->rays[i].x_intersect >= 0
			&& info->rays[i].x_intersect < WINDOW_WIDTH))
		info->rays[i].horiz_distance = (float)INT_MAX;
}

void	find_horiz_delta(t_data *info, int i)
{
	info->rays[i].xstep = TILE_SIZE / tan(info->rays[i].angle);
	if (!info->rays[i].is_facing_right && info->rays[i].xstep > 0)
		info->rays[i].xstep *= -1;
	else if ((info->rays[i].is_facing_right && info->rays[i].xstep < 0))
		info->rays[i].xstep *= -1;
	if (!info->rays[i].is_facing_up)
		info->rays[i].ystep = TILE_SIZE;
	else
		info->rays[i].ystep = -TILE_SIZE;
}

void	find_horiz_wall_hit(t_data *info, int i)
{
	while ((info->rays[i].x_intersect >= 0
			&& info->rays[i].x_intersect <= WINDOW_WIDTH)
		&& (info->rays[i].y_intersect >= 0
			&& info->rays[i].y_intersect <= WINDOW_HEIGHT))
	{
		if (intersect_collision(info, i, info->rays[i].x_intersect,
				info->rays[i].y_intersect - info->rays[i].is_facing_up))
		{
			info->rays[i].horiz_hit_x = info->rays[i].x_intersect;
			info->rays[i].horiz_hit_y = info->rays[i].y_intersect;
			break ;
		}
		info->rays[i].x_intersect += info->rays[i].xstep;
		info->rays[i].y_intersect += info->rays[i].ystep;
	}
}

void	get_horizontal_distance(t_data *info, int i)
{
	find_first_horiz_intersect(info, i);
	if (info->rays[i].horiz_distance != (float)INT_MAX)
	{
		find_horiz_delta(info, i);
		find_horiz_wall_hit(info, i);
	}
	if (intersect_collision(info, i, info->rays[i].x_intersect,
			info->rays[i].y_intersect - info->rays[i].is_facing_up))
		info->rays[i].horiz_distance = get_distance(info,
				info->rays[i].x_intersect, info->rays[i].y_intersect);
	else
		info->rays[i].horiz_distance = (float)INT_MAX;
}
