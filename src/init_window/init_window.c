/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/09/20 15:39:04 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	put_map_to_window(int x, int y, unsigned int color, t_cub3d *data)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while (block_y < BLOCK_SIZE - 1)
	{
		block_x = 0;
		while (block_x < BLOCK_SIZE - 1)
		{
			my_mlx_pixel_put(data, x + block_x, y + block_y, color);
			block_x++;
		}
		block_y++;
	}
}

static void	create_player(t_cub3d *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < PLAYER_SIZE)
	{
		j = -1;
		while (++j < PLAYER_SIZE)
		{
			my_mlx_pixel_put(data, x + j, y + i, color);
		}
	}
}

void	draw_player(t_cub3d *data)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while (block_y < data->height + 1)
	{
		block_x = 0;
		while (block_x < data->width + 1)
		{
			create_player(data, data->player_x * PLAYER_SIZE, \
			data->player_y * PLAYER_SIZE, data->color[2]);
			block_x++;
		}
		block_y++;
	}
}

void	draw_map(t_cub3d *data)
{
	int				y;
	int				x;
	unsigned int	color;

	y = 0;
	while (y < data->height + 1)
	{
		x = 0;
		while (x < data->width + 1)
		{
			if (x < (int)ft_strlen(data->raw_map[y]) && \
			data->raw_map[y][x] == '1')
				color = data->color[1];
			else if (x < (int)ft_strlen(data->raw_map[y]) && \
			(data->raw_map[y][x] == '0' \
			|| (x < (int)ft_strlen(data->raw_map[y]) && \
			check_character(data->raw_map[y][x], 2))))
				color = data->color[0];
			else
				color = 0x0000FF;
			put_map_to_window(x * BLOCK_SIZE, y * BLOCK_SIZE, color, data);
			x++;
		}
		y++;
	}
}

void	image_handler(t_cub3d *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	render_background(data);
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx_ptr, \
	data->mlx_window, data->img->img_ptr, 0, 0);
}

void	init_window(t_cub3d *data)
{
	data->color[0] = 0xFFFFFF;
	data->color[1] = 0xFFA500;
	data->color[2] = 0xFF0000;
	data->player_x *= (BLOCK_SIZE / PLAYER_SIZE);
	data->player_y *= (BLOCK_SIZE / PLAYER_SIZE);
	data->mlx_ptr = mlx_init();
	//protect mlx_ptr
	data->mlx_window = mlx_new_window(data->mlx_ptr, X, \
							Y, "Cub3D");
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, X, Y);
	//protect mlx_window
	//protect img_ptr
}
