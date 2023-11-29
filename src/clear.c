/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:33:26 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/29 12:06:58 by clbernar         ###   ########.fr       */
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
	if (info->rays != NULL)
		free(info->rays);
}

int	clear(t_data *info)
{
	free_t_data(info);
	clear_window(info);
	return (0);
}

void	destroy_xpm(t_data *info)
{
	if (info->textures[NO].img)
		mlx_destroy_image(info->mlx, info->textures[NO].img);
	if (info->textures[SO].img)
		mlx_destroy_image(info->mlx, info->textures[SO].img);
	if (info->textures[EA].img)
		mlx_destroy_image(info->mlx, info->textures[EA].img);
	if (info->textures[WE].img)
		mlx_destroy_image(info->mlx, info->textures[WE].img);
}
