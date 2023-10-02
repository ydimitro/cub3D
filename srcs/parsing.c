/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:41:49 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 12:27:01 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * FUNCTION: (check_for_elements) just matches the the Texure name with the
 * 				one in the buffer if it finds it then it uses the function
 * 				(take_care_of_texure) to save it up the in the main struct as
 * 				a texure.
 */
void	check_for_elements(char *buffer, t_main *main)
{
	if (match("NO", buffer) == true)
		take_care_of_texure(buffer, main, 'N');
	else if (match("SO", buffer) == true)
		take_care_of_texure(buffer, main, 'S');
	else if (match("WE", buffer) == true)
		take_care_of_texure(buffer, main, 'W');
	else if (match("EA", buffer) == true)
		take_care_of_texure(buffer, main, 'E');
	else if (match("F", buffer) == true)
		take_care_of_color(buffer, main, 'F');
	else if (match("C", buffer) == true)
		take_care_of_color(buffer, main, 'C');
}


/**
 * FUNCTION: (find_elements) uses a while loop to scan through the file
 * 				and checks for the possible map elements using:
 * 				(check_for_elements) function.
 */
void	find_elements(t_main *main)
{
	char	*buffer;

	buffer = get_next_line(main->file_fd);
	while (buffer != NULL)
	{	

		check_for_elements(buffer, main);
		free(buffer);
		buffer = get_next_line(main->file_fd);
	}
	if (buffer != NULL)
		free(buffer);
	close(main->file_fd);
}

/**
 * FUNCTION: (find_map) skips everything in the file till it finds the map
 * 				then it goes through it and checks for empty lines or
 * 				information that should not be contained inside of the map.
 * 				Then it uses (save_map) function to save the map.
 */
static void	find_map(t_main *main, char **argv)
{
	int		len;
	int		c;
	char	*buffer;

	len = 0;
	c = 0;
	buffer = get_next_line(main->file_fd);
	while (buffer != NULL && check_for_map_start(buffer, main) == false)
	{
		free(buffer);
		buffer = get_next_line(main->file_fd);
	}
	while (buffer != NULL)
	{
		len++;
		if (check_map_fragments(main, buffer, &c) == 1 && c == 2)
			parsing_cleaning(main, buffer, EMPTY_LINE_IN_MAP);
		free(buffer);
		buffer = get_next_line(main->file_fd);
	}
	save_map(main, argv, len);
}

/**
 * FUNCTION: (check_for_open_walls) checks for open walls
 * 				1. Checks the top and bottom of the map
 * 					would be closed.
 * 				2. @check_spaces: it goes through the map and check
 * 					checks if the space is surounded by the walls.
 * 					If not it prints the error.
 */
static void	check_for_open_walls(t_main *main)
{
	int	i;
	int	len;

	i = 0;
	len = main->height - 1;
	if (main->height < 3)
		parsing_cleaning(main, NULL, MAP_IS_NOT_CLOSED);
	while (main->map[0][i] != '\0' && \
			main->map[0][i] != '0' && main->map[0][i] != main->p_dir)
		i++;
	if (main->map[0][i] == '0' || main->map[0][i] == main->p_dir)
		parsing_cleaning(main, NULL, MAP_IS_NOT_CLOSED);
	i = 0;
	while (main->map[len][i] != '\0' && \
			main->map[len][i] != '0' && main->map[len][i] != main->p_dir)
		i++;
	if (main->map[len][i] == '0' || main->map[len][i] == main->p_dir)
		parsing_cleaning(main, NULL, MAP_IS_NOT_CLOSED);
	check_spaces(main, 0, 0);
}

/**
 * FUNCTION: (parsing) hauses the functions that are used to do the parsing.
 * 				1. @find_elements: it goes through the file and checks for the
 * 					elements like: texures of the walls and the ceiling and floor colors.
 * 				2. @find_map: it uses it to locate the map in the file and save it.
 * 				3. @check_player_direction: it checks for the players location.
 * 				4. @check_for_open_walls: it checks for the open walls.
 */
void	parsing(t_main *main, char **argv)
{
	find_elements(main);
	open_the_file(main, argv);
	find_map(main, argv);
	check_player_direction(main);
	main->p_x = main->p_pos_x;
	main->p_y = main->p_pos_y;
	check_for_open_walls(main);
}
