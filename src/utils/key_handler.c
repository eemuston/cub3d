/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:42 by vvu               #+#    #+#             */
/*   Updated: 2023/09/19 18:44:41 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	mouse_handler(t_cub3d *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	free_texture(data);
	exit(0);
}

static void	move(t_cub3d *data, int height, int width)
{
	if (data->raw_map[height / (BLOCK_SIZE / PLAYER_SIZE)] \
					[width / (BLOCK_SIZE / PLAYER_SIZE)] == '1')
		return ;
	else
	{
		data->player_x = width;
		data->player_y = height;
		mlx_clear_window(data->mlx_ptr, data->mlx_window);
		image_handler(data);
	}
}

void	moving_keys(int key, t_cub3d *data)
{
	if (key == W_KEY)
		data->tmp_player_y--;
	if (key == S_KEY)
		data->tmp_player_y++;
	if (key == A_KEY)
		data->tmp_player_x--;
	if (key == D_KEY)
		data->tmp_player_x++;
}

int	key_handler(int key, t_cub3d *data)
{
	data->tmp_player_x = data->player_x;
	data->tmp_player_y = data->player_y;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		free_texture(data);
		exit(0);
	}
	if (key == 13 || key == 0 || key == 1 || key == 2)
	{
		moving_keys(key, data);
		if (data->player_x != data->tmp_player_x || \
		data->player_y != data->tmp_player_y)
			move(data, data->tmp_player_y, data->tmp_player_x);
	}
	return (0);
}
