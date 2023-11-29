/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:28:41 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/29 16:00:56 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_release(int keycode, t_data *info)
{
	if (keycode == FRONT)
		info->player.walk_direction = 0;
	else if (keycode == BACK)
		info->player.walk_direction = 0;
	else if (keycode == LEFT)
		info->player.turn_direction = 0;
	else if (keycode == RIGHT)
		info->player.turn_direction = 0;
	else if (keycode == R_LEFT)
		info->player.rotate_direction = 0;
	else if (keycode == R_RIGHT)
		info->player.rotate_direction = 0;
	return (0);
}

int	key_press(int keycode, t_data *info)
{
	if (keycode == 0xFF1B)
		clear(info);
	if (keycode == FRONT)
		info->player.walk_direction = 1;
	else if (keycode == BACK)
		info->player.walk_direction = -1;
	else if (keycode == LEFT)
		info->player.turn_direction = -1;
	else if (keycode == RIGHT)
		info->player.turn_direction = 1;
	else if (keycode == R_LEFT)
		info->player.rotate_direction = -1;
	else if (keycode == R_RIGHT)
		info->player.rotate_direction = 1;
	return (0);
}

// Tester les retours de fonction / Sortir en cas d'erreur
void	init_window(t_data *info)
{
	info->mlx = mlx_init();
	init_textures(info);
	get_textures_addresses(info);
	mlx_get_screen_size(info->mlx, &(info->win_width), &(info->win_height));
	info->win = mlx_new_window(info->mlx,
			info->win_width, info->win_height, "Cub3d");
	info->nb_rays = info->win_width;
	info->rays = malloc(sizeof(t_ray) * (info->nb_rays));
	if (!info->rays)
		return (free_t_data(info), clear_window(info));
	mlx_hook(info->win, DestroyNotify, StructureNotifyMask, clear, info);
	mlx_hook(info->win, KeyPress, KeyPressMask, key_press, info);
	mlx_hook(info->win, KeyRelease, KeyReleaseMask, key_release, info);
	info->img.img = mlx_new_image(info->mlx, info->win_width, info->win_height);
	info->img.addr = mlx_get_data_addr(info->img.img,
			&(info->img.bits_per_pixel), &(info->img.line_length),
			&(info->img.endian));
	info->img2.img = mlx_new_image(info->mlx, info->win_width,
			info->win_height);
	info->img2.addr = mlx_get_data_addr(info->img2.img,
			&(info->img2.bits_per_pixel), &(info->img2.line_length),
			&(info->img2.endian));
	mlx_loop_hook(info->mlx, draw, info);
	mlx_loop(info->mlx);
}

void	clear_window(t_data *info)
{
	destroy_xpm(info);
	if (info->img.img)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->img2.img)
		mlx_destroy_image(info->mlx, info->img2.img);
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->mlx)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
	}
	if (!info->textures[NO].img || !info->textures[SO].img
		|| !info->textures[EA].img || !info->textures[WE].img)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

void	my_mlx_pixel_put(t_imge *image, int x, int y, int color)
{
	char	*img;

	img = image->addr + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	*(unsigned int *)img = color;
}
