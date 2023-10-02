/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:41:39 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 18:48:54 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	match(char *searched, char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	while (searched[x] != '\0' && str[i] != '\0' && searched[x] == str[i])
	{
		x++;
		i++;
	}
	if (searched[x] == '\0' && str[i] == ' ')
		return (true);
	return (false);
}

void	open_the_file(t_main *main, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exiterr(FILE_IS_NOT_THERE);
	main->file_fd = fd;
}

/*
Checking that the file extension is .cub
 */
void	check_file_extension(char *filename)
{
	int		i;
	char	*file_ex;

	i = ft_strlen(filename);
	file_ex = ft_substr(filename, i - 4, 4);
	if (ft_strncmp(file_ex, ".cub", ft_strlen(".cub")) != 0)
	{
		free(file_ex);
		ft_exiterr(WRONG_FILE_EXTENSION);
	}
	free(file_ex);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

/*
Helper function to trim leading and trailing whitespaces.
*/
char	*trim_whitespace(char *str)
{
	char	*start;
	char	*end;
	int		i;
	int		j;

	while (*str && (char)ft_isspace(*str))
		str++;
	start = str;
	end = start + ft_strlen(start) - 1;
	while (end > start && ft_isspace(*end))
		end--;
	*(end + 1) = '\0';
	i = 0;
	j = 0;
	while (start[i])
	{
		if (!ft_isspace(start[i]) || (i > 0 && !ft_isspace(start[i - 1])))
			start[j++] = start[i];
		i++;
	}
	start[j] = '\0';
	return (ft_strdup(start));
}
