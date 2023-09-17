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

#include "../includes/cub3d.h"

//starting direction
void handle_error(int code)
{
	if (code == ERR_MULTIPLE_START) {
		ft_putstr("Error: Multiple starting positions detected in the map.\n");
	} else if (code == ERR_NO_START) {
		ft_putstr("Error: No starting position detected in the map.\n");
	} // You can add more conditions here as needed.

	// free any allocated memory, close any open files, etc.

	exit(code); // Exit with the error code
}