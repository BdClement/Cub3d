/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:18:26 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/15 22:07:37 by clbernar         ###   ########.fr       */
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
	// Init a reorganise pour le Player !!
	info->player.turnDirection = 0;
	info->player.walkDirection = 0;
	info->player.rotateDirection = 0;
	info->player.walkSpeed = 5;
	info->player.rotationSpeed = 3 * (M_PI / 180);
	// info->player.rotationAngle = fait dans parsing_map3
}
