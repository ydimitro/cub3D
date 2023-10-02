/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:39:47 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 13:34:26 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
char *trim_whitespace(char *str)
{
    char *start;
    char *end;
    int i;
	int	j;

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
    return ft_strdup(start);
}

/*
Validating whether the provided values represent valid RGB color components
(0 to 255 values).
check_nbr: Variable to store the integer conversion of the current string.
*/
static bool	confirm_possible_color_val(char **val)
{
	int	i;
	int	x;
	int	check_nbr;

	i = 0;
	x = 0;
	check_nbr = 0;
	while (val[i] != NULL)
	{
		while (val[i][x] != '\0')
		{
			if (val[i][x] < '0' || val[i][x] > '9')
				return (false);
			x++;
		}
		check_nbr = ft_atoi(val[i]);
		if (check_nbr < 0 || check_nbr > 255)
			return (false);
		x = 0;
		i++;
	}
	if (i != 3)
		return (false);
	return (true);
}

/*
Processing and validating RGB color values provided in a string format.
Extract the relevant portion of the buffer and store it in val.
[] ignore whitespaces
Split the val string into an array of strings based on the comma separator.
*/
void	take_care_of_color(char *buffer, t_main *m, char id)
{
	int		i;
	char	*val;
	char	*trimmed_val;
	char	**c;

	i = 0;
	val = save_element(m, buffer);
	trimmed_val = trim_whitespace(val);
	c = ft_split(val, ',');
	if (confirm_possible_color_val(c) == false)
	{
		while (c[i] != NULL)
			free(c[i++]);
		free(c);
		parsing_cleaning(m, val, INCORECT_COLOR_VAL);
	}
	if (id == 'F')
		m->floor = (ft_atoi(c[0]) << 16) + \
										(ft_atoi(c[1]) << 8) + ft_atoi(c[2]);
	else
		m->ceiling = (ft_atoi(c[0]) << 16) + (ft_atoi(c[1]) << 8) + ft_atoi(c[2]);	
	while (c[i] != NULL)
		free(c[i++]);
	free(c);
	free(val);
}
