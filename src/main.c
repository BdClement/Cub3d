/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:27:14 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/14 19:31:37 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
//valgrind --leak-check=full --show-leak-kinds=all  ./cub3d map/test.cub

int	main(int argc, char **argv)
{
	t_data	info;

	if (argc != 2)
		ft_printf("Error.\nThis program requires one argument.\n");
	else
	{
		init_t_data(&info);
		parsing_is_ok(argv[1], &info);
		init_window(&info);
		display2d_map(&info);
		// ft_printf("Sortie de init_window\n");
		// while (1)
		// {
		// 	sleep(10);
		// 	ft_printf("Test\n");
		// 	// detect_action();
		// 	// update();
		// 	// display();
		// }
		mlx_loop(info.mlx);
	}
	return (0);
}
