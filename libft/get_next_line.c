/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:57:36 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/18 23:42:05 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

//A static variable is a variable that has been allocated 
//statically—whose lifetime (or "extent") is the entire run of the program.

static char	*ft_read_line(int fd, char *buffer)
{
	char	*temp_buffer;
	int		count_bytes;

	count_bytes = 1;
	temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (0);
	while (count_bytes != 0 && !ft_gnl_strchr(buffer, '\n'))
	{
		count_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free(temp_buffer);
			free(buffer);
			return (0);
		}
		temp_buffer[count_bytes] = '\0';
		buffer = ft_gnl_strjoin(buffer, temp_buffer);
	}
	free(temp_buffer);
	return (buffer);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		size;

	size = 0;
	if (!*buffer)
		return (0);
	while (buffer[size] && buffer[size] != '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (!line)
		return (0);
	size = 0;
	while (buffer[size] && buffer[size] != '\n')
	{
		line[size] = buffer[size];
		size++;
	}
	if (buffer[size] == '\n')
	{
		line[size] = buffer[size];
		size++;
	}
	line[size] = '\0';
	return (line);
}

static char	*ft_update_line(char *buffer)
{
	int		x;
	int		j;
	char	*new_buffer;

	x = 0;
	j = 0;
	while (buffer[x] && buffer[x] != '\n')
		x++;
	if (!buffer[x])
	{
		free(buffer);
		return (0);
	}
	new_buffer = (char *)malloc(sizeof(char) * (ft_gnl_strlen(buffer) + 1));
	if (!new_buffer)
		return (0);
	x++;
	while (buffer[x])
		new_buffer[j++] = buffer[x++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_get_line(buffer);
	buffer = ft_update_line(buffer);
	return (line);
}
