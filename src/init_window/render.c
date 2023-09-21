/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:34:34 by vvu               #+#    #+#             */
/*   Updated: 2023/09/21 17:04:32 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	render_background(t_cub3d *data)
{
	int	y;
	int	x;
	int	color;

	color = 0x58ABE5;
	y = -1;
	while (++y < Y)
	{
		x = -1;
		while (++x < X)
		{
			my_mlx_pixel_put(data, x, y, color);
		}
	}
}

void	draw_2d_direction(t_cub3d *data)
{
	t_line	line;
	t_point	p1;
	t_point	p2;

	line.dx = 0;
	p1.p_x = (data->player->player_x * BLOCK_SIZE / PLAYER_SIZE) + PLAYER_SIZE / 2;
	p2.p_x = (data->player->player_x * BLOCK_SIZE / PLAYER_SIZE) + PLAYER_SIZE / 2;
	p1.p_y = data->player->player_y * BLOCK_SIZE / PLAYER_SIZE;
	p2.p_y = data->player->player_y * BLOCK_SIZE / PLAYER_SIZE - 10 ;
	bresenham(p1, p2, data, line);
}

void	render_game(t_cub3d *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	render_background(data);
	draw_2d_map(data);
	draw_2d_player(data);
	draw_2d_direction(data);
	mlx_put_image_to_window(data->mlx_ptr, \
	data->mlx_window, data->img->img_ptr, 0, 0);
}
