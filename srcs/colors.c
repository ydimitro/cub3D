/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:39:47 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 16:55:29 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
Norminette help function of take_care_of_color()
*/
void	free_color_array(char **c)
{
	int	i;

	i = 0;
	while (c[i] != NULL)
		free(c[i++]);
	free(c);
}

/*
Processing and validating RGB color values provided in a string format.
Extract the relevant portion of the buffer and store it in val.
[] ignore whitespaces
Split the val string into an array of strings based on the comma separator.
*/
void	take_care_of_color(char *buffer, t_main *m, char id)
{
	char	*val;
	char	*trimmed_val;
	char	**c;

	val = save_element(m, buffer);
	trimmed_val = trim_whitespace(val);
	c = ft_split(val, ',');
	if (confirm_possible_color_val(c) == false)
	{
		free_color_array(c);
		parsing_cleaning(m, val, INCORECT_COLOR_VAL);
	}
	if (id == 'F')
		m->floor = (ft_atoi(c[0]) << 16) + \
										(ft_atoi(c[1]) << 8) + ft_atoi(c[2]);
	else
		m->ceiling = (ft_atoi(c[0]) << 16) + \
										(ft_atoi(c[1]) << 8) + ft_atoi(c[2]);
	free(val);
}
