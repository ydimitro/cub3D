/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:21:56 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 23:21:56 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void set_player_start(t_data *data, char orientation, int x, int y, int *player_start_found)
{
	if (*player_start_found) {
		return ERR_MULTIPLE_START;
	}

	*player_start_found = 1;

	data->player.x = x; //  + 0.5 for Center of the tile
	data->player.y = y; //  + 0.5 for Center of the tile

	if (orientation == 'NO') {
		data->player_dir = 90.0;
	} else if (orientation == 'EA') {
		data->player_dir = 0.0;
	} else if (orientation == 'SO') {
		data->player_dir = 270.0;
	} else if (orientation == 'WE') {
		data->player_dir = 180.0;
	}
/*
	if (orientation == 'NO') {
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	} else if (orientation == 'SO') {
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	} else if (orientation == 'EA') {
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	} else if (orientation == 'WE') {
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
*/
	
	return SUCCESS;
}

// During map parsing
int row = 0;
while ((line = get_next_line(fd)) != NULL)
{
	...
	int col = 0;
	while (line[col])
	{
		if (strchr("NOSOEAWE", line[col]))
			set_player_start(&data, line[col], col, row);
		col++;
	}
	row++;
}
