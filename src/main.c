/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:27:14 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/08 18:51:31 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
//valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all  ./cub3d map.cub

int	main(int argc, char **argv)
{
	t_data	info;

	if (argc != 2)
		ft_printf("Error.\nThis program requires one argument.\n");
	else
	{
		init_t_data(&info);
		parsing_is_ok(argv[1], &info);
		ft_printf("TOUT EST CARRE MA GUEULE\n");
		free_t_data(&info);//tests
	}
	return (0);
}
