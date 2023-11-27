/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:28 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/27 19:56:51 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_textures(t_data *info)
{
	info->textures[NO].img = mlx_xpm_file_to_image(info->mlx,
			info->north_texture, info->textures[NO].width,
			info->textures[NO].height);
	info->textures[SO].img = mlx_xpm_file_to_image(info->mlx,
			info->south_texture, info->textures[SO].width,
			info->textures[SO].height);
	info->textures[EA].img = mlx_xpm_file_to_image(info->mlx,
			info->east_texture, info->textures[EA].width,
			info->textures[EA].height);
	info->textures[WE].img = mlx_xpm_file_to_image(info->mlx,
			info->west_texture, info->textures[WE].width,
			info->textures[WE].height);
	if (!info->textures[NO].img || !info->textures[SO].img
		|| !info->textures[EA].img || !info->textures[WE].img)
	{
		printf("Error.\nxpm file not found.\n");
		clear(info);
	}
}

void	get_textures_addresses(t_data *info)
{
	info->textures[NO].addr = mlx_get_data_addr(info->textures[NO].img,
			&(info->textures[NO].bits_per_pixel),
			&(info->textures[NO].line_length),
			&(info->textures[NO].endian));
	info->textures[SO].addr = mlx_get_data_addr(info->textures[SO].img,
			&(info->textures[SO].bits_per_pixel),
			&(info->textures[SO].line_length),
			&(info->textures[SO].endian));
	info->textures[EA].addr = mlx_get_data_addr(info->textures[EA].img,
			&(info->textures[EA].bits_per_pixel),
			&(info->textures[EA].line_length),
			&(info->textures[EA].endian));
	info->textures[WE].addr = mlx_get_data_addr(info->textures[WE].img,
			&(info->textures[WE].bits_per_pixel),
			&(info->textures[WE].line_length),
			&(info->textures[WE].endian));
}

void	draw_texture(t_data *info, int x, int y)
{
	int		start;
	int		text_num;
	//int		text_color;
	double	offset_x;
	double	offset_y;
	double distance_from_top;

	start = (WINDOW_HEIGHT / 2) - (info->rays[x].wall_height / 2);
	if (info->rays[x].hit_is_vert)
	{
		offset_x = y % TILE_SIZE;
		if (info->rays[x].is_facing_right)
			text_num = WE;
		else
			text_num = EA;
	}
	else
	{
		offset_x = x % TILE_SIZE;
		if (info->rays[x].is_facing_up)
			text_num = SO;
		else
			text_num = NO;
	}
	// calcul offset y
	distance_from_top = y + ((int)info->rays[x].wall_height / 2) - (WINDOW_WIDTH / 2)
	offset_y = distance_from_top * (info->text_color[text_num].height / (int)info->rays[x].wall_height);
}
