/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:34:34 by vvu               #+#    #+#             */
/*   Updated: 2023/10/04 11:54:01 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

double	degree_to_rad(double angle)
{
	return (angle * M_PI / 180.0);
}

void	render_background(t_cub3d *data)
{
	int	y;
	int	x;
	int	color;

	color = 0x58ABE5;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			// my_mlx_pixel_put(data, x, y, color);
			my_mlx_pixel_put_mini(data, x, y, color);
		}
	}
}

void	draw_2d_direction(t_cub3d *data)
{
	t_line	line;
	t_point	p1;
	t_point	p2;

	line.dx = 0;
	p1.p_x = data->player->player_x * PLAYER_SIZE + PLAYER_SIZE / 2;
	p1.p_y = data->player->player_y * PLAYER_SIZE + PLAYER_SIZE / 2;
	p2.p_x = (data->player->player_x * PLAYER_SIZE + PLAYER_SIZE / 2)
		+ data->player->pdx * 10;
	p2.p_y = (data->player->player_y * PLAYER_SIZE + PLAYER_SIZE / 2)
		+ data->player->pdy * 10;
	dda_algorithm(p1, p2, data, line);
}

void	render_game(t_cub3d *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	// render_background(data);
	draw_2d_map(data);
	draw_2d_player(data);
	draw_2d_direction(data);
	draw_fov(data);
	mlx_put_image_to_window(data->mlx_ptr, \
		data->mlx_window, data->img->img_ptr, 0, 0);
}
