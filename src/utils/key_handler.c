/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:42 by vvu               #+#    #+#             */
/*   Updated: 2023/09/17 17:03:39 by vvu              ###   ########.fr       */
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
	if (data->raw_map[height / 2][width / 2] == '1')
		return ;
	else
	{
		data->player_x = width;
		data->player_y = height;
		mlx_clear_window(data->mlx, data->mlx_window);
		draw_map(data);
		draw_player(data);
	}
}

void	moving_keys(int key, t_cub3d *data)
{
	int	tempx;
	int	tempy;

	tempx = data->tmp_player_x;
	tempy = data->tmp_player_y;
	if (key == 13) // W
		data->tmp_player_y -= 1;
	if (key == 1) // S
		data->tmp_player_y += 1;
	if (key == 0) // A
		data->tmp_player_x -= 1;
	if (key == 2) //D
		data->tmp_player_x += 1;
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
		moving_keys(key, data);
		if (data->player_x * 2 != data->tmp_player_x || \
		data->player_y * 2 != data->tmp_player_y)
		move(data, data->tmp_player_y, data->tmp_player_x);
	}
	return (0);
}
