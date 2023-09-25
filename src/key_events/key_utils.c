/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:17:44 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/25 15:36:14 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

// static int	qualify_move(t_cub3d *data, int height, int width)
// {
// 	// if ((data->raw_map[(height - 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
// 	// 				[(width - 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
// 	// 	|| (data->raw_map[(height + 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
// 	// 				[(width + 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
// 	// 	|| (data->raw_map[(height) / (BLOCK_SIZE / PLAYER_SIZE)] \
// 	// 				[(width + 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
// 	// 	|| (data->raw_map[(height + 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
// 	// 				[(width) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
// 	// 	|| (data->raw_map[(height) / (BLOCK_SIZE / PLAYER_SIZE)] \
// 	// 				[(width - 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
// 	// 	|| (data->raw_map[(height - 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
// 	// 				[(width) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
// 	// 	|| (data->raw_map[(height - 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
// 	// 				[(width + 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
// 	// 	|| (data->raw_map[(height + 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
// 	// 				[(width - 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1'))
// 	// 	return (1);
	
// 	return (0);
// }

void	move(t_cub3d *data, double height, double width)
{
	// if (qualify_move(data, (int)height, (int)width))
	// 	return ;
	printf("height: %f\n", height);
	printf("width: %f\n", width);
	int	y;
	int x;
	y = round(height);
	x = round(width);
	if (data->raw_map[y / (BLOCK_SIZE / PLAYER_SIZE)]\
		[x / (BLOCK_SIZE / PLAYER_SIZE)] == '1')
		return ;
	else
	{
		data->player->player_x = width;
		data->player->player_y = height;
		mlx_clear_window(data->mlx_ptr, data->mlx_window);
		render_game(data);
	}
}
