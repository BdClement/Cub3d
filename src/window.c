/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:28:41 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/15 13:37:04 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	test(int keycode, t_data *info)
{
	if (keycode == 0xFF1B)
		clear(info);
	if (keycode == 119)
		ft_printf("W pressed\n");
	else if (keycode == 115)
		ft_printf("S pressed\n");
	else if (keycode == 97)
		ft_printf("A pressed\n");
	else if (keycode == 100)
		ft_printf("D pressed\n");
	else if (keycode == 65361)
		ft_printf("Fleche de gauche\n");
	else if (keycode == 65363)
		ft_printf("Fleche de droite\n");
	// else
	// 	ft_printf("%d\n", keycode);
	return (0);
}

// Tester les retours de fonction / Sortir en cas d'erreur
void	init_window(t_data *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	mlx_hook(info->win, DestroyNotify, StructureNotifyMask, clear, info);
	mlx_hook(info->win, KeyPress, KeyPressMask, test, info);
	info->img.img = mlx_new_image(info->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	info->img.addr = mlx_get_data_addr(info->img.img, &(info->img.bits_per_pixel), &(info->img.line_length), &(info->img.endian));
	mlx_loop_hook(info->mlx, display2d_map, info);
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
