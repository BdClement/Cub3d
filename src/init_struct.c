/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:18:26 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/29 16:02:10 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function initialize a t_data structure
void	init_t_data(t_data *info)
{
	info->file = NULL;
	info->map = NULL;
	info->north_texture = NULL;
	info->south_texture = NULL;
	info->east_texture = NULL;
	info->west_texture = NULL;
	info->floor_color[0] = -1;
	info->ceiling_color[0] = -1;
	info->mlx = NULL;
	info->win = NULL;
	info->img.img = NULL;
	info->img2.img = NULL;
	info->rays = NULL;
	info->textures[NO].img = NULL;
	info->textures[SO].img = NULL;
	info->textures[EA].img = NULL;
	info->textures[WE].img = NULL;
	init_t_player(info);
}

void	init_t_player(t_data *info)
{
	info->player.turn_direction = 0;
	info->player.walk_direction = 0;
	info->player.rotate_direction = 0;
	info->player.walk_speed = 10;
	info->player.rotation_speed = 3 * (M_PI / 180);
}

void	init_ray(t_data *info, int i)
{
	info->rays[i].horiz_hit_x = 0;
	info->rays[i].horiz_hit_y = 0;
	info->rays[i].vert_hit_x = 0;
	info->rays[i].vert_hit_y = 0;
	info->rays[i].horiz_distance = 0;
	info->rays[i].vert_distance = 0;
	info->rays[i].hit_is_vert = 0;
}
