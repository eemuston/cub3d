/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:34:34 by vvu               #+#    #+#             */
/*   Updated: 2023/10/10 16:32:24 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

double	degree_to_rad(double angle)
{
	return (angle * M_PI / 180.0);
}

void	render_background(t_cub3d *data)
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

void	clear_image(t_cub3d *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(data, x, y, 0x000000);
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
	draw_2d_map(data);
	draw_2d_player(data);
	draw_2d_direction(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img->img_ptr,
		0, 0);
}
