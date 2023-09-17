/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/09/17 17:02:07 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	put_map_to_window(int x, int y, char c, t_cub3d *data)
{
	int	color;
	int	block_x;
	int	block_y;

	color = 0;
	block_y = 0;
	if (c == '1')
		color = data->color[1];
	else if (c == '0' || check_character(c, 2))
		color = data->color[0];
	while (block_y < 10 - 1)
	{
		block_x = 0;
		while (block_x < 10 - 1)
		{
			mlx_pixel_put(data->mlx, data->mlx_window, x * 10 + block_x, \
			y * 10 + block_y, color);
			block_x++;
		}
		block_y++;
	}
}

void	draw_player(t_cub3d *data)
{
	int	block_x;
	int	block_y;

	block_y = 0;
	while (block_y < 5)
	{
		block_x = 0;
		while (block_x < 5)
		{
			mlx_pixel_put(data->mlx, data->mlx_window, data->player_x * 5 \
			+ block_x, data->player_y * 5 + block_y, data->color[2]);
			block_x++;
		}
		block_y++;
	}
}

void	draw_map(t_cub3d *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < (int)ft_strlen(data->raw_map[y]))
		{
			put_map_to_window(x, y, data->raw_map[y][x], data);
			x++;
		}
		y++;
	}
}

void	image_handler(t_cub3d *data)
{
	draw_map(data);
	draw_player(data);
	mlx_hook(data->mlx_window, 2, 1L << 1, key_handler, data);
	mlx_hook(data->mlx_window, 17, 0, mouse_handler, data);
	mlx_loop(data->mlx);
}

void	init_window(t_cub3d *data)
{
	data->color[0] = 0xFFFFFF;
	data->color[1] = 0x0000FF;
	data->color[2] = 0xFF0000;
	data->player_x *= 2;
	data->player_y *= 2;
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, 1098, \
							800, "Cub3D");
	image_handler(data);
}
