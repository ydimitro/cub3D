/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:30:49 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/27 18:56:38 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
int ft_isspace(int c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return(1);
	return(0);
}

// static int is_all_spaces(const char *line)
// {
//     for (int i = 0; line[i] != '\0'; i++) {
//         if (!ft_isspace(line[i])) {
//             return 0; // Not all spaces
//         }
//     }
//     return 1; // All spaces
// }

int	get_map(char *line, t_data *data)
{
  
	printf("%s\n", line);
	// printf("\n");
	return 0;
}
