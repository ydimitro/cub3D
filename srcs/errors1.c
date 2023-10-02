/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:40:42 by ydimitro          #+#    #+#             */
/*   Updated: 2023/10/02 11:40:44 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * FUNCTION: (check_file_extension) checks that the file
 * 				extension would be .cub
 */
void	check_file_extension(char *filename)
{
	int		i;
	char	*file_ex;

	i = ft_strlen(filename);
	file_ex = ft_substr(filename, i - 4, 4);
	if (ft_strncmp(file_ex, ".cub", ft_strlen(".cub")) != 0)
	{
		free(file_ex);
		ft_exiterr(WRONG_FILE_EXTENSION);
	}
	free(file_ex);
}
