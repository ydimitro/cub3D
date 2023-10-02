

#include "../includes/cub3d.h"

void	load_texure(t_texture *t, t_wall *h, char *t_path)
{
	t->h = 0;
	t->w = 0;
	t->img = mlx_xpm_file_to_image(h->vars->mlx, t_path, &t->w, &t->h);
	if (t->img == NULL)
		ft_exiterr(XPM_HAS_FAILED_TO_OPEN);
	t->data = mlx_get_data_addr(t->img, &t->bpp, &t->size_line, &t->endian);
	mlx_put_image_to_window(h->vars->mlx, h->vars->win, t->img, t->w, t->h);
}

char	*prepare_element_path(char *str)
{
	int		len;
	char	*element_path;

	len = 0;
	element_path = NULL;
	if (str == NULL)
		ft_exiterr(MISSING_ELEMENT_PATH);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	element_path = ft_calloc(len + 1, sizeof(char));
	element_path[len] = '\0';
	len--;
	while (len >= 0)
	{
		element_path[len] = str[len];
		len--;
	}
	return (element_path);
}

void	free_splitted(char **split, char *element_name)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
	free(element_name);
}

char	*save_element(t_main *main, char *buffer)
{
	int		i;
	char	*element_name;
	char	*element_path;
	char	**split;

	i = 0;
	element_name = NULL;
	element_path = NULL;
	split = ft_split(buffer, ' ');
	while (split[i] != NULL)
		i++;
	if (i != 2)
	{
		free_splitted(split, element_name);
		clear_the_main_struct(main);
		ft_exiterr(FOUND_ELEMENT_TRASH);
	}
	element_path = prepare_element_path(split[1]);
	free_splitted(split, element_name);
	return (element_path);
}

void	take_care_of_texure(char *buffer, t_main *main, char name)
{
	if (name == 'N')
	{
		if (main->north_t != NULL)
			free(main->north_t);
		main->north_t = save_element(main, buffer);
	}
	else if (name == 'S')
	{
		if (main->south_t != NULL)
			free(main->south_t);
		main->south_t = save_element(main, buffer);
	}
	else if (name == 'W')
	{
		if (main->west_t != NULL)
			free(main->west_t);
		main->west_t = save_element(main, buffer);
	}
	else if (name == 'E')
	{
		if (main->east_t != NULL)
			free(main->east_t);
		main->east_t = save_element(main, buffer);
	}
}
