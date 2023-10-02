/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:40:32 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 12:27:01 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	first_error_messages(int err)
{
	if (err == SPEED_TO_LITTLE)
		ft_putstr_fd(RED "Speed should be more than 4!\n" B, 2);
	else if (err == DEFAULT_CEILING_COLOR)
		ft_putstr_fd(RED "Default ceiling color has to be: 0xE11E00!\n" B, 2);
	else if (err == DEFAULT_FLOOR_COLOR)
		ft_putstr_fd(RED "Default floor color has to be: 0xDC6400!\n" B, 2);
	else if (err == TILE_SIZE)
		ft_putstr_fd(RED "Tile size should be 32x32!\n" B, 2);
	else if (err == SCREEN_SIZE)
		ft_putstr_fd(RED "Screen size should be 720x1280!\n" B, 2);
	else if (err == NOT_ENOUGH_ARGS)
		ft_putstr_fd(RED "Not enough arguments!\n" B, 2);
	else if (err == INVALID_ARGS)
		ft_putstr_fd(RED "Invalid arguments!\n" B, 2);
	else if (err == WRONG_FILE_EXTENSION)
		ft_putstr_fd(RED "Invalid file Ext! Only files with [.cub] Ext!\n" B, 2);
	else if (err == FILE_IS_NOT_THERE)
		ft_putstr_fd(RED "File does not exist!\n" B, 2);
	else if (err == INCORECT_FILE_CONFIG)
		ft_putstr_fd(RED "Map has to be the last in config file!\n" B, 2);
	else if (err == CUB_CONTAINS_TRASH)
		ft_putstr_fd(RED ".cub file contains trash characters!\n" B, 2);
	if (err >= -5 && err <= 6)
		return (1);
	return (0);
}

/**
 * FUNCTION: (ft_exiterr) is responsible for matching the err number with
 * 				its error and outputting the error message into the terminal
 * 				using ft_putstr_fd.
 */
void	ft_exiterr(int err)
{
	if (first_error_messages(err) == 1)
		exit (err);
	else if (err == MISSING_ELEMENT_PATH)
		ft_putstr_fd(RED "Texure path is not specified!\n" B, 2);
	else if (err == FOUND_ELEMENT_TRASH)
		ft_putstr_fd(RED "Please check the texure field!\n" B, 2);
	else if (err == INCORECT_COLOR_VAL)
		ft_putstr_fd(RED "Invalid color: 0-255,0-255,0-255\n" B, 2);
	else if (err == TAB_IN_MAP_FOUND)
		ft_putstr_fd(RED "Check Map there are tabs!\n" B, 2);
	else if (err == MAP_NOT_CLOSED)
		ft_putstr_fd(RED "Map is not closed!\n" B, 2);
	else if (err == WRONG_INFO_IN_MAP)
		ft_putstr_fd(RED "ERROR map possible characters: 'NSEW10 '!\n" B, 2);
	else if (err == EMPTY_LINE_IN_MAP)
		ft_putstr_fd(RED "Empty line beetween the map lines!\n" B, 2);
	else if (err == MORE_THAN_ONE_PLAYER)
		ft_putstr_fd(RED "There is more than 1 player!\n" B, 2);
	else if (err == MAP_IS_NOT_CLOSED)
		ft_putstr_fd(RED "Map is not closed!\n" B, 2);
	else if (err == PLAYER_DOES_NOT_EXIST)
		ft_putstr_fd(RED "Player does not exist in the map!\n" B, 2);
	else if (err == XPM_HAS_FAILED_TO_OPEN)
		ft_putstr_fd(RED "XPM has failed to be opened!\n" B, 2);
	exit (err);
}

/**
 * FUNCTION: (check_for_tabs) checks for the tab in the given line.
 * 				if it finds one it outputs and error because subject
 * 				pdf specifies that only spaces should be valid.
 */
static void	check_for_tabs(t_main *main, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\t')
		i++;
	if (buffer[i] != '\0' && buffer[i] == '\t')
		parsing_cleaning(main, buffer, TAB_IN_MAP_FOUND);
}

/**
 * FUNCTION: (check_file_config) it just checks that the map
 * 				would be after the information about the map like
 * 				ceiling floor color and the texures for each wall.
 * 				Also, checks for the tab using (check_for_tabs) function.
 */
static void	check_file_config(t_main *main)
{
	bool	map_found;
	char	*buffer;

	map_found = false;
	buffer = get_next_line(main->file_fd);
	while (buffer != NULL)
	{
		check_for_tabs(main, buffer);
		if (map_found == false)
			map_found = map_fragment_found(buffer);
		if (component_found(buffer) == true && map_found == true)
		{
			free(buffer);
			close(main->file_fd);
			ft_exiterr(INCORECT_FILE_CONFIG);
		}
		find_trash(main, buffer);
		free(buffer);
		buffer = get_next_line(main->file_fd);
	}
}

/**
 * FUNCTION: (check_basic_erros) performs checks before the map is parsed.
 *		1. @argument_ammount: it checks if the argument ammount is correct.
		2. @check_file_extension: it checks that the file extension would be .cub
 * 		3. @open_the_file: it OPENS the given file and checks the file descriptor if
 * 				its a valid one it saves it in the struct.
 * 		4. @check_file_config: Checks for any tabs. It checks that the information
 * 			about the map would be before the map itself. it checks that there would
 * 			not be anything that is not supposed to be there according to pdf.
 */
void	check_basic_errors(t_main *main, int argc, char **argv)
{
	if (argc != 2)
		ft_exiterr(NOT_ENOUGH_ARGS);
	if (TILE != 32)
		parsing_cleaning(main, NULL, TILE_SIZE);
	if (S_WIDTH != 1280)
		parsing_cleaning(main, NULL, SCREEN_SIZE);
	if (S_HEIGHT != 720)
		parsing_cleaning(main, NULL, SCREEN_SIZE);
	if (D_F != 0xDC6400)
		parsing_cleaning(main, NULL, DEFAULT_FLOOR_COLOR);
	if (D_C != 0xE11E00)
		parsing_cleaning(main, NULL, DEFAULT_CEILING_COLOR);
	check_file_extension(argv[1]);
	open_the_file(main, argv);
	check_file_config(main);
	close(main->file_fd);
	open_the_file(main, argv);
}
