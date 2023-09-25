/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:42 by vvu               #+#    #+#             */
/*   Updated: 2023/09/25 13:37:49 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	mouse_handler(t_cub3d *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	free_texture(data);
	exit(0);
}

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

static void	move(t_cub3d *data, int height, int width)
{
	if (qualify_move(data, height, width))
		return ;
	else
	{
		data->player->player_x = width;
		data->player->player_y = height;
		mlx_clear_window(data->mlx_ptr, data->mlx_window);
		render_game(data);
	}
}

void	moving_keys(int key, t_cub3d *data)
{
	double	player_rad_angle;

	player_rad_angle = data->player->player_angle * M_PI / 180.0;
	if (key == W)
	{
		data->player->tmp_player_x -= cos(player_rad_angle);
		data->player->tmp_player_y -= sin(player_rad_angle);
	}
	if (key == S)
	{
		data->player->tmp_player_x += cos(player_rad_angle);
		data->player->tmp_player_y += sin(player_rad_angle);
	}
	if (key == A)
	{
		data->player->tmp_player_x -= sin(player_rad_angle);
		data->player->tmp_player_y += cos(player_rad_angle);
	}
	if (key == D)
	{
		data->player->tmp_player_x += sin(player_rad_angle);
		data->player->tmp_player_y -= cos(player_rad_angle);
	}
	if (key == RIGHT)
	{
		data->player->player_angle += 90;
		if (data->player->player_angle >= 360)
			data->player->player_angle -= 360;
	}
	if (key == LEFT)
	{
		data->player->player_angle -= 90;
		if (data->player->player_angle < 0)
			data->player->player_angle += 360;
	}
	if (data->player->player_angle >= 360)
		data->player->player_angle -= 360;
	if (data->player->player_angle < 0)
		data->player->player_angle += 360;
	// printf("Angle: %f\n", data->player->player_angle);
}

int	key_handler(int key, t_cub3d *data)
{
	data->player->tmp_player_x = data->player->player_x;
	data->player->tmp_player_y = data->player->player_y;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		free_texture(data);
		exit(0);
	}
	if (key == W || key == A || key == S || key == D || key == LEFT || \
	key == RIGHT)
	{
		moving_keys(key, data);
		if (data->player->player_x != data->player->tmp_player_x || \
			data->player->player_y != data->player->tmp_player_y)
			move(data, data->player->tmp_player_y, data->player->tmp_player_x);
	}
	return (0);
}
