/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:27:14 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/03 19:50:47 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	info;
	//Structure Parsing a creer et envoyer a parsing_is_ok

	if (argc != 2)
		ft_printf("Error.\nThis program requires one argument.\n");
	else
	{
		ft_printf("strncmp == %d\n", ft_strncmp("NO", "NO", 2));
		init_t_data(&info);
		if (!parsing_is_ok(argv[1], &info))
			return (1);
	}
	return (0);
}
