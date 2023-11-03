/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:25:37 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/03 18:25:39 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	display_tab(char **tab)
{
	int	i;

	i = 0;
	// if (tab != NULL && tab[0] != NULL && tab[0][0] == '\0')
	// 	ft_printf("Le tableau a afficher est NULL\n");
	while (tab[i] != NULL)
	{
		ft_printf("%s", tab[i]);
		i++;
	}
}

int	get_len_tab(char **tab)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (tab == NULL)
		return (len);
	while (tab[i] != NULL)
	{
		len++;
		i++;
	}
	return (len);
}

int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
