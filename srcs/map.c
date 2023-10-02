/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:41:26 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 11:41:29 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*save_map_line(char *buffer)
{
	int		len;
	char	*map_line;

	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	map_line = malloc((len + 1) * sizeof(char));
	map_line[len--] = '\0';
	while (len >= 0)
	{
		map_line[len] = buffer[len];
		len--;
	}
	return (map_line);
}

void	save_map(t_main *main, char **argv, int len)
{
	int		i;
	char	*buffer;

	i = 0;
	close(main->file_fd);
	open_the_file(main, argv);
	buffer = get_next_line(main->file_fd);
	while (buffer != NULL && check_for_map_start(buffer, main) == false)
	{
		free(buffer);
		buffer = get_next_line(main->file_fd);
	}
	main->map = malloc((len + 1) * sizeof(char *));
	while (buffer != NULL && i < len)
	{
		main->map[i] = save_map_line(buffer);
		free(buffer);
		buffer = get_next_line(main->file_fd);
		i++;
	}
	main->map[i] = NULL;
	main->height = len;
	close(main->file_fd);
}

bool	check_for_map_start(char *buffer, t_main *main)
{
	int	i;

	i = 0;
	(void)main;
	while (buffer[i] != '\0' && (buffer[i] == ' ' || buffer[i] == '\t'))
		i++;
	if (buffer[i] != '\0' && (buffer[i] == '0' || buffer[i] == '1'))
		return (true);
	return (false);
}

int	map_skip_space(int i, char *b, char id)
{
	int	x;

	x = 0;
	if (id == '+')
	{
		while (b[i] != '\0' && b[i] == ' ')
			i++;
		return (i);
	}
	if (id == '-')
	{
		x = ft_strlen(b) - 1;
		if (b[x] == '\n')
			x--;
		while (x > i && b[x] == ' ')
			x--;
		return (x);
	}
	return (0);
}

int	check_map_fragments(t_main *main, char *b, int *c)
{
	int	i;
	int	x;

	i = map_skip_space(0, b, '+');
	x = map_skip_space(i, b, '-');
	if (x == -1 || x < i)
	{
		*c = 2;
		return (2);
	}
	if (b[x] != '1' || b[i] != '1')
		parsing_cleaning(main, b, MAP_NOT_CLOSED);
	while (b[i] != '\0' && i != x)
	{
		if (b[i] == '1' || b[i] == '0' || b[i] == 'N' || b[i] == 'S' || \
			b[i] == 'E' || b[i] == 'W' || b[i] == ' ')
			i++;
		else if (b[i] == '\t')
			parsing_cleaning(main, b, TAB_IN_MAP_FOUND);
		else
			parsing_cleaning(main, b, WRONG_INFO_IN_MAP);
	}
	return (1);
}
