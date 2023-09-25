/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:31:31 by vvu               #+#    #+#             */
/*   Updated: 2023/09/25 13:26:17 by eemuston         ###   ########.fr       */
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
	i = 0;
}

void	draw_2d_player(t_cub3d *data)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while (block_y < data->height + 1)
	{
		block_x = 0;
		while (block_x < data->width + 1)
		{
			create_player(data, data->player->player_x * PLAYER_SIZE, \
			data->player->player_y * PLAYER_SIZE, data->color[2]);
			block_x++;
			printf("player_y = %f\n", data->player->player_y * PLAYER_SIZE);
			printf("player_x = %f\n", data->player->player_x * PLAYER_SIZE);
		}
		block_y++;
	}
}

void	draw_2d_map(t_cub3d *data)
{
	int				y;
	int				x;
	unsigned int	color;

	y = -1;
	while (++y < data->height + 1)
	{
		x = -1;
		while (++x < data->width + 1)
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
		}
	}
}
