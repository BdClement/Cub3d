/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:28:41 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/15 22:09:35 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_release(int keycode, t_data *info)
{
	if (keycode == FRONT)
		info->player.walkDirection = 0;
	else if (keycode == BACK)
		info->player.walkDirection = 0;
	else if (keycode == LEFT)
		info->player.turnDirection = 0;
	else if (keycode == RIGHT)
		info->player.turnDirection = 0;
	else if (keycode == R_LEFT)
		info->player.rotateDirection = 0;
	else if (keycode == R_RIGHT)
		info->player.rotateDirection = 0;
	printf("turnDirection = %d\n", info->player.turnDirection);
	return (0);
}

int	key_press(int keycode, t_data *info)
{
	if (keycode == 0xFF1B)
		clear(info);
	if (keycode == FRONT)
		info->player.walkDirection = 1;
	else if (keycode == BACK)
		info->player.walkDirection = -1;
	else if (keycode == LEFT)
		info->player.turnDirection = -1;
	else if (keycode == RIGHT)
		info->player.turnDirection = 1;
	else if (keycode == R_LEFT)
		info->player.rotateDirection = -1;
	else if (keycode == R_RIGHT)
		info->player.rotateDirection = 1;
	printf("turnDirection = %d\n", info->player.turnDirection);
	return (0);
}

// Tester les retours de fonction / Sortir en cas d'erreur
void	init_window(t_data *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	mlx_hook(info->win, DestroyNotify, StructureNotifyMask, clear, info);
	mlx_hook(info->win, KeyPress, KeyPressMask, key_press, info);
	mlx_hook(info->win, KeyRelease, KeyReleaseMask, key_release, info);
	info->img.img = mlx_new_image(info->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	info->img.addr = mlx_get_data_addr(info->img.img, &(info->img.bits_per_pixel), &(info->img.line_length), &(info->img.endian));
	mlx_loop_hook(info->mlx, draw, info);
	mlx_loop(info->mlx);
}

void	clear_window(t_data *info)
{
	// mlx_loop_end(info->mlx);
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
	*(unsigned int *)img = color;
}
