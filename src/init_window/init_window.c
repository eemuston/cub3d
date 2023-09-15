/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/09/15 17:57:48 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	put_map_to_window(int x, int y, char c, t_cub3d *data)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	x = x * BLOCK_SIZE;
	y = y * BLOCK_SIZE;
	while (block_y < BLOCK_SIZE)
	{
		block_x = 0;
		while (block_x < BLOCK_SIZE)
		{
			if (c == '1')
				mlx_pixel_put(data->mlx, data->mlx_window, x + block_x, y \
						+ block_y, data->color[0]);
			block_x++;
		}
		block_y++;
	}
}

static void	put_player_on_map(int x, int y, t_cub3d *data)
{
	int	block_y;
	int	block_x;
	int	x_size;
	int	y_size;

	x = x * BLOCK_SIZE;
	y = y * BLOCK_SIZE;
	block_y = 0;
	while (block_y < PLAYER_SIZE)
	{
		block_x = 0;
		while (block_x < PLAYER_SIZE)
		{
			x_size = x + block_x + (BLOCK_SIZE - PLAYER_SIZE) / 2;
			y_size = y + block_y + (BLOCK_SIZE - PLAYER_SIZE) / 2;
			mlx_pixel_put(data->mlx, data->mlx_window, x_size, y_size, \
					data->color[2]);
			block_x++;
		}
		block_y++;
	}
}

void	put_to_win(t_cub3d *data)
{
	int	y;
	int	x;
	int	flag;

	y = 0;
	flag = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < (int)ft_strlen(data->raw_map[y]))
		{
			if (check_character(data->raw_map[y][x], 2))
			{
				data->raw_map[y][x] = '0';
				flag = 1;
			}
			put_map_to_window(x, y, data->raw_map[y][x], data);
			if (flag == 1)
			{
				put_player_on_map(x, y, data);
				flag = 0;
			}
			x++;
		}
		y++;
	}
}

void	image_handler(t_cub3d *data)
{
	put_to_win(data);
	mlx_hook(data->mlx_window, 2, 1L << 1, key_handler, data);
	mlx_hook(data->mlx_window, 17, 0, mouse_handler, data);
	mlx_loop(data->mlx);
}

void	init_window(t_cub3d *data)
{
	data->color[0] = 0xFFFFFF;
	data->color[1] = 0x0000FF;
	data->color[2] = 0xFF0000;
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, \
										data->width * (BLOCK_SIZE * 2), \
										data->height * (BLOCK_SIZE * 2), \
										"Cub3D");
	image_handler(data);
}
