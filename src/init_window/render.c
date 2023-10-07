/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:34:34 by vvu               #+#    #+#             */
/*   Updated: 2023/10/07 17:11:02 by vvu              ###   ########.fr       */
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

	color = data->ceil_color;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		if (y == HEIGHT / 2)
			color = data->floor_color;
		while (++x < WIDTH)
			my_mlx_pixel_put(data, x, y, color);
	}
}

void	draw_2d_direction(t_cub3d *data)
{
	t_line	line;
	t_point	p1;
	t_point	p2;

	line.dx = 0;
	p1.p_x = data->player->player_x * BLOCK_SIZE + PLAYER_SIZE / 2;
	p1.p_y = data->player->player_y * BLOCK_SIZE + PLAYER_SIZE / 2;
	p2.p_x = (data->player->player_x * BLOCK_SIZE + PLAYER_SIZE / 2)
		+ data->player->pdx * 20;
	p2.p_y = (data->player->player_y * BLOCK_SIZE + PLAYER_SIZE / 2)
		+ data->player->pdy * 20;
	dda_algorithm(p1, p2, data, line);
}

void clear_image(t_cub3d *data)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			my_mlx_pixel_put(data, x, y, 0x000000);
		}
	}
}


void	render_game(t_cub3d *data)
{
	clear_image(data);
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	render_background(data);
	draw_fov(data);
	draw_2d_map(data);
	draw_2d_player(data);
	draw_2d_direction(data);
	printf("player_x: %f\n", data->player->player_x);
	printf("player_y: %f\n", data->player->player_y);
	printf("player_angle: %f\n", data->player->player_angle);
	mlx_put_image_to_window(data->mlx_ptr, \
		data->mlx_window, data->img->img_ptr, 0, 0);
}
