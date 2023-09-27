/* ************************************************************************** */
/*                    */
/*              :::    ::::::::   */
/*   textures_parse.c                     :+:   :+:   :+:   */
/*              +:+ +:+    +:+   */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg>    +#+  +:+       +#+  */
/*            +#+#+#+#+#+   +#+  */
/*   Created: 2023/09/18 23:45:38 by tgomes-l      #+#  #+#        */
/*   Updated: 2023/09/27 02:08:34 by tgomes-l      ###   ########.fr   */
/*                    */
/* ************************************************************************** */

#include "cub3d.h"

// Function to parse texture-and-color-related lines

int get_elements(char *line, t_data *data)
{
	if(strstr(line, "NO") || strstr(line, "SO") || strstr(line, "WE") || strstr(line, "EA"))
		parse_texture(line, data);
	else if(strstr(line, "EA"))
		parse_texture(line, data);
	// else if(strstr(line, "F") || strstr(line, "C"))
	//  	parse_color(line, data);
	
	return (0);
}

int	parse_texture(char *line, t_data *data)
{
    int i = 0;
        
    // Skip leading spaces
    while (ft_isspace(line[i]))
    {
        i++;
    }
        
    // Find the texture path
    char *texture_path = strstr(line + i, "./");
        
    if (texture_path) {
        // Remove trailing spaces (if any)
        int len = strlen(texture_path);
        while (len > 0 && ft_isspace(texture_path[len - 1])) {
            len--;
        }
        texture_path[len] = '\0'; // Null-terminate the path
        
        if (strstr(line, "NO")) {
            data->north = strdup(texture_path);
        } else if (strstr(line, "SO")) {
            data->south = strdup(texture_path);
        } else if (strstr(line, "WE")) {
            data->west = strdup(texture_path);
        } else if (strstr(line, "EA")) {
            data->east = strdup(texture_path);
        }
    }
    return 0;
}

// int	parse_color(char *line, t_data *data)
// {
// 	int i = 0;
// 	char *color_digits;
	
// 	while(ft_isspace(line[i]))
// 		i++;
// 	if (!line[i])
//   return 0;
// ////missssiing code
// 	return (0);
// }