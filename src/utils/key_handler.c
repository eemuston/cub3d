/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:42 by vvu               #+#    #+#             */
/*   Updated: 2023/09/13 16:27:37 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	mouse_handler(t_cub3d *data)
{
	mlx_destroy_window(data->mlx, data->mlx_window);
	free_texture(data);
	exit(0);
}

static void	move(t_cub3d *data, int height, int width)
{
	if (data->raw_map[height][width] == '1')
		return ;
	else
	{
		if (data->raw_map[height][width] == '0')
			data->raw_map[height][width] = data->player_direction;
		data->player_x = width;
		data->player_y = height;
		mlx_clear_window(data->mlx, data->mlx_window);
		put_to_win(data);
	}
}

void	moving_keys(int key, t_cub3d *data)
{
	if (key == 13 && data->raw_map[data->tmp_player_y - 1][data->tmp_player_x] == '0') //w key
		data->tmp_player_y--;
	if (key == 1 && data->raw_map[data->tmp_player_y + 1][data->tmp_player_x] == '0') //S
		data->tmp_player_y++;
	if (key == 0 && data->raw_map[data->tmp_player_y][data->tmp_player_x - 1] == '0') // A
		data->tmp_player_x--;
	if (key == 2 && data->raw_map[data->tmp_player_y][data->tmp_player_x + 1] == '0') //D
		data->tmp_player_x++;
}

int	key_handler(int key, t_cub3d *data)
{
	data->tmp_player_x = data->player_x;
	data->tmp_player_y = data->player_y;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_window);
		free_texture(data);
		exit(0);
	}
	if (key == 13 || key == 0 || key == 1 || key == 2)
	{
		data->raw_map[data->tmp_player_y][data->tmp_player_x] = '0';
		moving_keys(key, data);
		if (data->player_x != data->tmp_player_x || \
		data->player_y != data->tmp_player_y)
		{
			move(data, data->tmp_player_y, data->tmp_player_x);
		}
	}
	return (0);
}
