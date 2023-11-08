/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:25:37 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/08 18:54:40 by clbernar         ###   ########.fr       */
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
	while (tab[i] != NULL)
	{
		ft_printf("%s\n", tab[i]);
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

// Check if the atoi of the string is bigger than an int
int	overflow(const char *nptr)
{
	long int	value;
	int			sign;

	value = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (ft_strlen(nptr) == 0 || ft_isdigit(*nptr) == 0)
		return (1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		value = value * 10 + (*nptr - 48);
		nptr++;
		if ((value * sign) > INT_MAX || (value * sign) < INT_MIN)
			return (1);
	}
	return (0);
}
