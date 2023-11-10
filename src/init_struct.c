/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:18:26 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/08 18:58:13 by clbernar         ###   ########.fr       */
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
}
