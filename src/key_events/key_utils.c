/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:17:44 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/11 17:44:09 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	not_qualify_move(t_cub3d *data, double height, double width)
{
	if ((data->raw_map[(int)(height - 0.3)] \
					[(int)(width - 0.3)] == '1') \
		|| (data->raw_map[(int)(height + 0.3)] \
					[(int)(width + 0.3)] == '1') \
		|| (data->raw_map[(int)(height)] \
					[(int)(width + 0.3)] == '1') \
		|| (data->raw_map[(int)(height + 0.3)] \
					[(int)(width)] == '1') \
		|| (data->raw_map[(int)(height)] \
					[(int)(width - 0.3)] == '1') \
		|| (data->raw_map[(int)(height - 0.3)] \
					[(int)(width)] == '1') \
		|| (data->raw_map[(int)(height - 0.3)] \
					[(int)(width + 0.3)] == '1') \
		|| (data->raw_map[(int)(height + 0.3)] \
					[(int)(width - 0.3)] == '1'))
		return (1);
	return (0);
}

void	update_player_coordinates(t_cub3d *data)
{
	double	x;
	double	y;

	y = data->player->tmp_player_y / BLOCK_SIZE;
	x = data->player->tmp_player_x / BLOCK_SIZE;
	if (not_qualify_move(data, y, x))
	{
		render_game(data);
		return ;
	}
	data->player->player_x = data->player->tmp_player_x / BLOCK_SIZE;
	data->player->player_y = data->player->tmp_player_y / BLOCK_SIZE;
	render_game(data);
}

void	arrow_keys(t_cub3d *data)
{
	if (data->keys[RIGHT])
	{
		data->player->player_angle -= ANGLE;
		if (data->player->player_angle < 0)
			data->player->player_angle += 360;
		data->player->pdx = cos(degree_to_rad(data->player->player_angle));
		data->player->pdy = -sin(degree_to_rad(data->player->player_angle));
	}
	if (data->keys[LEFT])
	{
		data->player->player_angle += ANGLE;
		if (data->player->player_angle >= 360)
			data->player->player_angle -= 360;
		data->player->pdx = cos(degree_to_rad(data->player->player_angle));
		data->player->pdy = -sin(degree_to_rad(data->player->player_angle));
	}
}

void	move_keys(t_cub3d *data)
{
	if (data->keys[W])
	{
		data->player->tmp_player_x += data->player->pdx * SPEED;
		data->player->tmp_player_y += data->player->pdy * SPEED;
	}
	if (data->keys[S])
	{
		data->player->tmp_player_x -= data->player->pdx * SPEED;
		data->player->tmp_player_y -= data->player->pdy * SPEED;
	}
	if (data->keys[A])
	{
		data->player->tmp_player_x += data->player->pdy * SPEED;
		data->player->tmp_player_y -= data->player->pdx * SPEED;
	}
	if (data->keys[D])
	{
		data->player->tmp_player_x -= data->player->pdy * SPEED;
		data->player->tmp_player_y += data->player->pdx * SPEED;
	}
}
