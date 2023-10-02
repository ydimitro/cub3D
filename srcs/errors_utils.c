/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:40:21 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 13:52:47 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Checks if the given string buffer starts with a map fragment, which is 
identified by the presence of '1' or '0' after any leading spaces.
*/
bool	map_fragment_found(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] == ' ')
		i++;
	if (buffer[i] == '1' || buffer[i] == '0')
		return (true);
	return (false);
}

/*
Checks if the given string name matches any of the predefined component names.
*/
bool	match_component_name(char *name)
{
	int	len_name;

	len_name = ft_strlen(name);
	if (ft_strncmp(name, "NO", len_name) == 0)
		return (true);
	if (ft_strncmp(name, "SO", len_name) == 0)
		return (true);
	if (ft_strncmp(name, "WE", len_name) == 0)
		return (true);
	if (ft_strncmp(name, "EA", len_name) == 0)
		return (true);
	if (ft_strncmp(name, "F", len_name) == 0)
		return (true);
	if (ft_strncmp(name, "C", len_name) == 0)
		return (true);
	return (false);
}

/*
Checks if the given string str contains a valid component 
name after any leading spaces and before any trailing spaces.
*/
bool	component_found(char *str)
{
	int		i;
	int		start;
	int		len;
	char	*name;
	bool	check;

	len = 0;
	start = 0;
	name = NULL;
	check = false;
	while (str[start] != '\0' && str[start] == ' ')
		start++;
	i = start;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	len = i;
	while (str[len] != '\0' && str[len] == ' ')
		len++;
	if (str[len] == '\0' || str[len] == '\n')
		return (false);
	name = ft_substr(str, start, i - start);
	check = match_component_name(name);
	free(name);
	return (check);
}

/*
Checks if the given string s contains any invalid content.
*/
void	find_trash(t_main *main, char *s)
{
	int	i;

	i = 0;
	if (map_fragment_found(s) == true || component_found(s) == true)
		return ;
	while (s[i] != '\0' && (ft_isspace(s[i])))
		i++;
	if (s[i] != '\0')
	{
		free (s);
		close(main->file_fd);
		ft_exiterr(CUB_CONTAINS_TRASH);
	}
}
