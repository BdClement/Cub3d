/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:33:26 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/17 14:31:49 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_t_data(t_data *info)
{
	if (info->file != NULL)
		free_tab(info->file);
	if (info->map != NULL)
		free_tab(info->map);
	if (info->north_texture != NULL)
		free(info->north_texture);
	if (info->south_texture != NULL)
		free(info->south_texture);
	if (info->east_texture != NULL)
		free(info->east_texture);
	if (info->west_texture != NULL)
		free(info->west_texture);
}

int	clear(t_data *info)
{
	free_t_data(info);
	clear_window(info);
	return (0);
}
