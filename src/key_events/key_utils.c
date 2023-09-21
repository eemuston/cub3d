/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:17:44 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/21 12:17:59 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	qualify_move(t_cub3d *data, int height, int width)
{
	if ((data->raw_map[(height - 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(width - 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(height + 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(width + 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(height) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(width + 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(height + 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(width) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(height) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(width - 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(height - 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(width) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(height - 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(width + 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(height + 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(width - 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1'))
		return (1);
	return (0);
}

void	move(t_cub3d *data, int height, int width)
{
	if (qualify_move(data, height, width))
		return ;
	else
	{
		data->player_x = width;
		data->player_y = height;
		mlx_clear_window(data->mlx_ptr, data->mlx_window);
		render_game(data);
	}
}
