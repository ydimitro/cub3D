
#include "../includes/cub3d.h"

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

void	take_care_of_color(char *buffer, t_main *m, char id)
{
	int		i;
	char	*val;
	char	**c;

	i = 0;
	val = save_element(m, buffer);
	c = ft_split(val, ',');
	if (confirm_possible_color_val(c) == false)
	{
		while (c[i] != NULL)
			free(c[i++]);
		free(c);
		parsing_cleaning(m, val, INCORECT_COLOR_VAL);
	}
	if (id == 'F')
		m->ground = (ft_atoi(c[0]) << 16) + \
										(ft_atoi(c[1]) << 8) + ft_atoi(c[2]);
	else
		m->roof = (ft_atoi(c[0]) << 16) + (ft_atoi(c[1]) << 8) + ft_atoi(c[2]);
	while (c[i] != NULL)
		free(c[i++]);
	free(c);
	free(val);
}
