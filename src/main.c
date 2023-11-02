/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:27:14 by bmirlico          #+#    #+#             */
/*   Updated: 2023/11/02 19:23:28 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	//Structure Parsing a creer et envoyer a parsing_is_ok
	if (argc != 2)
		ft_printf("Error.\nThis program requires one argument.\n");
	else
	{
		if (!parsing_is_ok(argv[1]))
			return (1);
	}
	return (0);
}
