/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:42 by vvu               #+#    #+#             */
/*   Updated: 2023/09/21 12:17:24 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	mouse_handler(t_cub3d *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	free_texture(data);
	exit(0);
}

static void	right_left_arrow_keys(int key, t_cub3d *data)
{
	if (key == RIGHT)
	{
		data->player_angle += 90;
		if (data->player_angle >= 360)
			data->player_angle -= 360;
	}
	else if (key == LEFT)
	{
		data->player_angle -= 90;
		if (data->player_angle < 0)
			data->player_angle += 360;
	}
	if (data->player_angle >= 360)
		data->player_angle -= 360;
	if (data->player_angle < 0)
		data->player_angle += 360;
}

void	moving_keys(int key, t_cub3d *data)
{
	double	player_rad_angle;

	player_rad_angle = data->player_angle * M_PI / 180.0;
	if (key == W)
	{
		data->tmp_player_x -= cos(player_rad_angle);
		data->tmp_player_y -= sin(player_rad_angle);
	}
	else if (key == S)
	{
		data->tmp_player_x += cos(player_rad_angle);
		data->tmp_player_y += sin(player_rad_angle);
	}
	else if (key == A)
	{
		data->tmp_player_x -= sin(player_rad_angle);
		data->tmp_player_y += cos(player_rad_angle);
	}
	else if (key == D)
	{
		data->tmp_player_x += sin(player_rad_angle);
		data->tmp_player_y -= cos(player_rad_angle);
	}
	else
		right_left_arrow_keys(key, data);
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
	if (key == W || key == A || key == S || key == D || key == LEFT || \
	key == RIGHT)
	{
		moving_keys(key, data);
		if (data->player_x != data->tmp_player_x || \
			data->player_y != data->tmp_player_y)
			move(data, data->tmp_player_y, data->tmp_player_x);
	}
	return (0);
}
