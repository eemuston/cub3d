/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:17:44 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/26 13:20:18 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	update_player_coordinates(t_cub3d *data)
{
	int	x;
	int	y;

	y = round(data->player->tmp_player_y);
	x = round(data->player->tmp_player_x);
	if (data->raw_map[y / (BLOCK_SIZE / PLAYER_SIZE)][x / (BLOCK_SIZE
			/ PLAYER_SIZE)] == '1')
		return ;
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
	}
	if (data->keys[LEFT])
	{
		data->player->player_angle -= ANGLE;
		if (data->player->player_angle < 0)
			data->player->player_angle += 360;
	}
}

void	move_keys(t_cub3d *data, double player_rad_angle)
{
	if (data->keys[W])
	{
		data->player->tmp_player_x -= cos(player_rad_angle) * SPEED;
		data->player->tmp_player_y -= sin(player_rad_angle) * SPEED;
	}
	if (data->keys[S])
	{
		data->player->tmp_player_x += cos(player_rad_angle) * SPEED;
		data->player->tmp_player_y += sin(player_rad_angle) * SPEED;
	}
	if (data->keys[A])
	{
		data->player->tmp_player_x -= sin(player_rad_angle) * SPEED;
		data->player->tmp_player_y += cos(player_rad_angle) * SPEED;
	}
	if (data->keys[D])
	{
		data->player->tmp_player_x += sin(player_rad_angle) * SPEED;
		data->player->tmp_player_y -= cos(player_rad_angle) * SPEED;
	}
}
