/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:27:33 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 23:27:33 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//starting direction
void handle_error(int code)
{
	if (code == SUCCESS)
		return ;
	else if (code == ERR_MULTIPLE_START) 
		ft_putstr("Error: Multiple starting positions detected in the map.\n");
	else if (code == ERR_NO_START) 
		ft_putstr("Error: No starting position detected in the map.\n");
	else if (code == ERR_INVALID_ARGC) 
        ft_putstr("Please execute like example: ./cub_3d maps/cub_3d\n");
    else if (code == ERR_INVALID_EXT) 
        ft_putstr("Invalid file extension. Only .cub files are supported.\n");
    else if (code == ERR_READ_FILE) 
        ft_putstr("An error occurred while reading the file.\n");
    else if (code == ERR_PLAYER_NR) 
        ft_putstr("Error: There should be only one player on the map.\n");
	else if (code == ERR_MAP_ALLOCATION_FAILED) 
    	ft_putstr("Error: Failed to allocate memory for the map.\n");
	else if (code == ERR_TEXTURE_LOAD_FAILED) 
    	ft_putstr("Error: Failed to load texture.\n");
	else if (code == ERR_EMPTY_MAP)
		ft_putstr("The map is empty\n");

	else
	exit(code);
}