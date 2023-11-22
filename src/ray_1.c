/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:04:48 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/22 15:16:50 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	raycasting(t_data *info)
{
	int	i;

	i = 0;
	while (i < NB_RAYS)
	{
		cast_one_ray(info, i);
		i++;
	}
	//cast_one_ray(info, i);
}

void	cast_one_ray(t_data *info, int i)
{
	set_ray(info, i);
	get_horizontal_distance(info, i);
	get_vertical_distance(info, i);
	draw_line(info, info->player.x, info->player.y, info->rays[i].wall_hit_x, info->rays[i].wall_hit_y, 0x00D8BE16);
}

// HORIZONTAL

void	get_horizontal_distance(t_data *info, int i)
{
	float	x_intersect;
	float	y_intersect;
	float	xstep;
	float	ystep;

	// find 1st horiz intersect
	y_intersect = floor(info->player.y / TILE_SIZE) * TILE_SIZE;
	if (!(info->rays[i].is_facing_up))
		y_intersect += TILE_SIZE;
	x_intersect = ((y_intersect - info->player.y) / tan(info->rays[i].angle)) + info->player.x;
	if (!(x_intersect >= 0 && x_intersect < WINDOW_WIDTH))
	{
		info->rays[i].distance_from_player = -1;
		return ;
	}
	// Find Delta
	xstep = TILE_SIZE / tan(info->rays[i].angle);
	if (!info->rays[i].is_facing_right && xstep > 0)
		xstep *= -1;
	else if ((info->rays[i].is_facing_right && xstep < 0))
		xstep *= -1;
	if (!info->rays[i].is_facing_up)
		ystep = TILE_SIZE;
	else
		ystep = -TILE_SIZE;
	// Loop while wall
	while ((x_intersect >= 0 && x_intersect <= WINDOW_WIDTH)
		&& (y_intersect >= 0 && y_intersect <= WINDOW_HEIGHT))
	{
		if (intersect_collision(info, i, x_intersect, y_intersect - info->rays[i].is_facing_up))
		{
			info->rays[i].wall_hit_x = x_intersect;
			info->rays[i].wall_hit_y = y_intersect;
			break ;
		}
		x_intersect += xstep;
		y_intersect += ystep;
	}
	info->rays[i].distance_from_player = get_distance(info,
			info->rays[i].wall_hit_x,
			info->rays[i].wall_hit_y);
	//draw_line(info, info->player.x, info->player.y, x_intersect, y_intersect, 0x003C59EB);
}

// VERTICAL

void	get_vertical_distance(t_data *info, int i)
{
	float	vertical_d;
	float	x_intersect;
	float	y_intersect;
	float	xstep;
	float	ystep;
	int		is_left;

	// Find 1st intersect
	x_intersect = floor(info->player.x / TILE_SIZE) * TILE_SIZE;
	if (info->rays[i].is_facing_right)
		x_intersect += TILE_SIZE;
	y_intersect = ((x_intersect - info->player.x) * tan(info->rays[i].angle)) + info->player.y;
	if (!(y_intersect >= 0 && y_intersect < WINDOW_HEIGHT))
		return ;
	// Find Delta
	ystep = TILE_SIZE * tan(info->rays[i].angle);
	if (info->rays[i].is_facing_up && ystep > 0)
		ystep *= -1;
	else if ((!info->rays[i].is_facing_up && ystep < 0))
		ystep *= -1;
	if (info->rays[i].is_facing_right)
		xstep = TILE_SIZE;
	else
		xstep = -TILE_SIZE;
	if (info->rays[i].is_facing_right)
		is_left = 0;
	else
		is_left = 1;
	while ((x_intersect >= 0 && x_intersect <= WINDOW_WIDTH)
		&& (y_intersect >= 0 && y_intersect <= WINDOW_HEIGHT))
	{
		if (intersect_collision(info, i, x_intersect - is_left, y_intersect))
			break ;
		x_intersect += xstep;
		y_intersect += ystep;
	}
	// comparaison a la fin des distances
	// if (i == 2303)
	// 	printf("[x: %2f, y:%2f]\n", x_intersect, y_intersect);
	vertical_d = get_distance(info, x_intersect, y_intersect);
	if (vertical_d < info->rays[i].distance_from_player
		|| info->rays[i].distance_from_player == -1)
	{
		info->rays[i].distance_from_player = vertical_d;
		info->rays[i].wall_hit_x = x_intersect;
		info->rays[i].wall_hit_y = y_intersect;
	}
	// if ((x_intersect >= 0 && x_intersect <= WINDOW_WIDTH)
	// 	&& (y_intersect >= 0 && y_intersect <= WINDOW_HEIGHT))
	// 	draw_line(info, info->player.x, info->player.y, x_intersect, y_intersect, 0x00099D09);
}

float	get_distance(t_data *info, float x, float y)
{
	float	distance;

	distance = sqrt(pow(x - info->player.x, 2) + pow(y - info->player.y, 2));
	return (distance);
}

void	set_ray(t_data *info, int i)
{
	// normalize angle
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
	//printf("nb: %d, value: [%2f]\n", i, info->rays[i].angle * 180 / M_PI);
	if (info->rays[i].angle >= 0 && info->rays[i].angle < M_PI)
		info->rays[i].is_facing_up = 0;
	else
		info->rays[i].is_facing_up = 1;
	if (info->rays[i].angle >= 90 * (M_PI / 180)
		&& info->rays[i].angle < 270 * (M_PI / 180))
		info->rays[i].is_facing_right = 0;
	else
		info->rays[i].is_facing_right = 1;

}

float	normalize_angle(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}
