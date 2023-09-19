/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/09/19 14:21:50 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	put_map_to_window(int x, int y, char **map, t_cub3d *data)
{
	int	color;
	int	block_y;
	int	block_x;

	color = 0;
	block_y = 0;
	if (map[y][x] != '\0' && map[y][x] == '1')
		color = data->color[1];
	else if (map[y][x] != '\0' && (map[y][x] == '0'
				|| check_character(map[y][x], 2) || map[y][x] == 32))
		color = data->color[0];
	else
		color = 0x00FFFF;
	while (block_y < BLOCK_SIZE - 1)
	{
		block_x = 0;
		while (block_x < BLOCK_SIZE - 1)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_window, x * BLOCK_SIZE \
					+ block_x, y * BLOCK_SIZE + block_y, color);
			block_x++;
		}
		block_y++;
	}
}

void	draw_player(t_cub3d *data)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while (block_y < PLAYER_SIZE)
	{
		block_x = 0;
		while (block_x < PLAYER_SIZE)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_window, data->player_x \
					* PLAYER_SIZE + block_x, data->player_y * PLAYER_SIZE \
					+ block_y, data->color[2]);
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
		while (x < data->width)
		{
			put_map_to_window(x, y, data->valid_map, data);
			x++;
		}
		y++;
	}
}

void	image_handler(t_cub3d *data)
{
	render_background(data);
	mlx_put_image_to_window(data->mlx_ptr, \
							data->mlx_window, \
							data->img->img_ptr, 0, 0);
	draw_map(data);
	draw_player(data);
}

void	init_window(t_cub3d *data)
{
	data->color[0] = 0xFFFFFF;
	data->color[1] = 0x0000FF;
	data->color[2] = 0xFF0000;
	data->player_x *= (BLOCK_SIZE / PLAYER_SIZE);
	data->player_y *= (BLOCK_SIZE / PLAYER_SIZE);
	data->mlx_ptr = mlx_init();
	//protect mlx_ptr
	data->mlx_window = mlx_new_window(data->mlx_ptr, X, Y, "Cub3D");
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, X, Y);
	//protect mlx_window
	//protect img_ptr
}
