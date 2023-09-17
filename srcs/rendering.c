/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:53:56 by ydimitro          #+#    #+#             */
/*   Updated: 2023/09/17 23:53:56 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Clear the previous frame.
2. For each vertical slice of the screen, cast a ray.
3. Based on where the ray hits a wall, determine the height of the wall slice to draw on the screen.
4. Draw the slice to the screen.
*/  

void render(t_data *data) 
{
	// 1. Clear the previous frame
	mlx_clear_window(data->mlx_ptr, data->win_ptr);

	// 2. For each vertical slice of the screen
	int x = 0;
	while (x < data->win_width) 
	{
		// Calculate initial ray direction based on player's direction and current slice
		float ray_angle = data->player_dir + (x - data->win_width / 2) * FOV / data->win_width;
		
		// Handle wrapping of angles (if angles are in degrees)
		if (ray_angle < 0) ray_angle += 360;
		if (ray_angle >= 360) ray_angle -= 360;

		// 3. Cast the ray and find out where it hits a wall using your preferred method
		cast_single_ray(data, x);

		// Determine height of the wall slice
		float slice_height = (data->tile_size / data->ray.perp_wall_dist) * DIST_TO_PROJ_PLANE;
		float top_pixel = (data->win_height / 2) - (slice_height / 2);
		top_pixel = (top_pixel < 0) ? 0 : top_pixel;
		float bottom_pixel = top_pixel + slice_height;
		bottom_pixel = (bottom_pixel > data->win_height) ? data->win_height : bottom_pixel;

		// 4. Draw the slice to the screen with the correct method
		if (data->ray.hit)
			draw_wall_slice(data, x);
		
		x++;
	}
	
	// Swap buffers or render the frame to the window, depending on MLX's functionality
	display_frame(data);
}
