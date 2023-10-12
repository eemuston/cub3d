/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:31:31 by vvu               #+#    #+#             */
/*   Updated: 2023/10/11 17:09:59 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	put_map_to_window(double x, double y, \
				unsigned int color, t_cub3d *data)
{
	int	block_y;
	int	block_x;

	block_y = 0;
	while (block_y < (BLOCK_SIZE) - 1)
	{
		block_x = 0;
		while (block_x < (BLOCK_SIZE) - 1)
		{
			my_mlx_pixel_put_mini(data, x + block_x, y + block_y, color);
			block_x++;
		}
		block_y++;
	}
}

static void	create_player(t_cub3d *data, double x, double y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < PLAYER_SIZE - 1)
	{
		j = -1;
		while (++j < PLAYER_SIZE - 1)
			my_mlx_pixel_put_mini(data, x + j, y + i, color);
	}
}

void	draw_2d_player(t_cub3d *data)
{
	create_player(data, (MINI_WIDTH / 2), \
			(MINI_HEIGHT / 2), data->color[2]);
}

static unsigned int	choose_color(t_cub3d *data, int x, int y)
{
	unsigned int	color;

	if (y >= 0 && y <= data->height && x >= 0 && x <= data->width \
	&& x < (int)ft_strlen(data->raw_map[y]) && \
	data->raw_map[y][x] == '1')
		color = data->color[1];
	else if (y >= 0 && y <= data->height && x >= 0 && \
	x <= data->width && x < (int)ft_strlen(data->raw_map[y]) && \
	(data->raw_map[y][x] == '0' \
	|| (x < (int)ft_strlen(data->raw_map[y]) && \
	check_character(data->raw_map[y][x], 2))))
		color = data->color[0];
	else
		color = 0x0000FF;
	return (color);
}

void	draw_2d_map(t_cub3d *data)
{
	int				y;
	int				x;
	double			start_x;
	double			start_y;

	start_x = data->player->player_x - 5;
	start_y = data->player->player_y - 5;
	y = start_y;
	while (y < start_y + 10)
	{
		x = start_x;
		while (x < start_x + 10)
		{
			put_map_to_window((x - start_x) * (BLOCK_SIZE), \
			(y - start_y) * (BLOCK_SIZE), choose_color(data, x, y), data);
			x++;
		}
		y++;
	}
}
