/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:50:49 by clbernar          #+#    #+#             */
/*   Updated: 2023/11/08 13:25:01 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function returns the number of lines in the file
int	get_file_nb_line(char *arg)
{
	char	*tmp;
	int		fd;
	int		nb_line;

	nb_line = 0;
	tmp = NULL;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		nb_line++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (close(fd) < 0)
		exit(EXIT_FAILURE);
	return (nb_line);
}

// This function get the content of the file and stocks it in a char**
char	**get_file_content(char *arg)
{
	int		fd;
	char	**file_content;
	int		i;
	char	*tmp;

	i = 0;
	file_content = NULL;
	tmp = NULL;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	file_content = malloc(sizeof(char *) * (get_file_nb_line(arg) + 1));
	if (file_content == NULL)
		exit(EXIT_FAILURE);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		file_content[i] = tmp;
		tmp = get_next_line(fd);
		i++;
	}
	file_content[i] = NULL;
	if (close(fd) < 0)
		exit(EXIT_FAILURE);
	return (file_content);
}

// This function contains all the parsing
// If the format has good format and exist, it collects the file's content
// And sends its content to be parsed
void	parsing_is_ok(char *arg, t_data *info)
{
	char	**file;

	format_cub_ok(arg);
	is_existing_file(arg);
	file = get_file_content(arg);
	parsing(file, info);
	file_is_complete(file, info);
	free_tab(file);// Test
}

// This function checks if map format is .cub or not
void	format_cub_ok(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[0] == '.')
			break ;
		if (arg[i] == '.')
		{
			if (arg[i + 1] == 'c' && arg[i + 2] == 'u'
				&& arg[i + 3] == 'b' && arg[i + 4] == '\0')
				return ;
		}
		i++;
	}
	ft_printf("Error.\nArgument's format is not as expected.\n");
	exit(EXIT_FAILURE);
	// return (0);
}

// This function checks if the file exist and if it's not a directory
void	is_existing_file(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
	{
		printf("%s is a directory.\n", str);
		if (close(fd) < 0)
			exit(EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_RDONLY, S_IRUSR);
	if (fd == -1)
	{
		printf("%s doesn't exist or doesn't have the right permissions.\n", str);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (close(fd) < 0)
			exit(EXIT_FAILURE);
	}
}
