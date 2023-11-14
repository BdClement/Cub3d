/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:28:41 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/14 15:19:00 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_window(t_data *info)
{
	info->mlx = mlx_init();
	// tester sinon salam
	info->win = mlx_new_window(info->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	// HOOK
	mlx_hook(info->win, DestroyNotify, StructureNotifyMask, clear, info);
	info->img.img = mlx_new_image(info->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	info->img.addr = mlx_get_data_addr(info->img.img, &(info->img.bits_per_pixel), &(info->img.line_length), &(info->img.endian));
	my_mlx_pixel_put(&info->img, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0x00FF0000);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	mlx_loop(info->mlx);
	// tester sinon salam
}

void	clear_window(t_data *info)
{
	mlx_loop_end(info->mlx);
	mlx_destroy_image(info->mlx, info->img.img);
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	exit(EXIT_SUCCESS);// Pourquoi ??
	// Tester sinon EXIT_FAILURE
}

void	my_mlx_pixel_put(t_imge *image, int x, int y, int color)
{
	char	*img;

	img = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)img = color;
}
