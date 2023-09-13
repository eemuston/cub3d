/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/09/13 16:50:34 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	put_map_to_window(int x, int y, char c, t_cub3d *data)
{
	int	color;
	int	block_y;
	int	block_x;

	block_y = 0;
	if (c == '1')
		color = data->color[1];
	else if (c == '0')
		color = data->color[0];
	while (block_y < 50)
	{
		block_x = 0;
		while (block_x < 50)
		{
			mlx_pixel_put(data->mlx, data->mlx_window,
				x * 50 + block_x, y * 50 + block_y, color);
			block_x++;
		}
		block_y++;
	}
}

static void	put_player_on_map(int x, int y, t_cub3d *data)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	x = x * 2;
	y = y * 2;
	while (block_y < 25)
	{
		block_x = 0;
		while (block_x < 25)
		{
			mlx_pixel_put(data->mlx, data->mlx_window, \
			x * 25 + block_x, y * 25 + block_y, data->color[2]);
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
	// mlx_key_hook(data->mlx_window, key_handler, data);
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
	data->mlx_window = mlx_new_window(data->mlx, data->width * 50, \
							data->height * 50, "Cub3D");
	image_handler(data);
}
