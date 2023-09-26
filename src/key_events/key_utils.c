/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:17:44 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/26 16:04:33 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	qualify_move(t_cub3d *data, double height, double width)
{
	if ((data->raw_map[(int)(height - 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(int)(width - 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(int)(height + 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(int)(width + 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(int)(height) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(int)(width + 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(int)(height + 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(int)(width) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(int)(height) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(int)(width - 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(int)(height - 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(int)(width) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(int)(height - 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(int)(width + 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1') \
		|| (data->raw_map[(int)(height + 1) / (BLOCK_SIZE / PLAYER_SIZE)] \
					[(int)(width - 1) / (BLOCK_SIZE / PLAYER_SIZE)] == '1'))
		return (1);
	return (0);
}

void	update_player_coordinates(t_cub3d *data)
{
	double	x;
	double	y;

	y = round(data->player->tmp_player_y);
	x = round(data->player->tmp_player_x);
	if (qualify_move(data, y, x))
	{
		render_game(data);
		return ;
	}
	data->player->player_x = data->player->tmp_player_x;
	data->player->player_y = data->player->tmp_player_y;
	render_game(data);
}

void	arrow_keys(t_cub3d *data)
{
	if (data->keys[RIGHT])
	{
		data->player->player_angle += ANGLE;
		if (data->player->player_angle >= 360)
			data->player->player_angle -= 360;
		data->player->pdx = cos(angle_rad(data->player->player_angle));
		data->player->pdy = sin(angle_rad(data->player->player_angle));
	}
	if (data->keys[LEFT])
	{
		data->player->player_angle -= ANGLE;
		if (data->player->player_angle < 0)
			data->player->player_angle += 360;
		data->player->pdx = cos(angle_rad(data->player->player_angle));
		data->player->pdy = sin(angle_rad(data->player->player_angle));
	}
}

void	move_keys(t_cub3d *data)
{
	if (data->keys[W])
	{
		data->player->tmp_player_x -= data->player->pdx * SPEED;
		data->player->tmp_player_y -= data->player->pdy * SPEED;
	}
	if (data->keys[S])
	{
		data->player->tmp_player_x += data->player->pdx * SPEED;
		data->player->tmp_player_y += data->player->pdy * SPEED;
	}
	if (data->keys[A])
	{
		data->player->tmp_player_x -= data->player->pdy * SPEED;
		data->player->tmp_player_y += data->player->pdx * SPEED;
	}
	if (data->keys[D])
	{
		data->player->tmp_player_x += data->player->pdy * SPEED;
		data->player->tmp_player_y -= data->player->pdx * SPEED;
	}
}
