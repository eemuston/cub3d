/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:22:59 by atoof             #+#    #+#             */
/*   Updated: 2023/10/14 15:23:00 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d_bonus.h"

static void	render_background(t_cub3d *data)
{
	int	color;
	int	y;
	int	x;

	color = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				color = data->ceil_color;
			else
				color = data->floor_color;
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_game(t_cub3d *data)
{
	clear_image(data);
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	render_background(data);
	ray_casting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img->img_ptr,
		0, 0);
	render_background_mini(data);
	draw_2d_map(data);
	draw_2d_player(data);
	draw_2d_direction(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, \
	data->mini_img->img_ptr, WIDTH - MINI_WIDTH, HEIGHT - MINI_HEIGHT);
}
