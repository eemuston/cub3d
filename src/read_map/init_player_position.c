/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:49:03 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/27 16:55:20 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	set_player_x_y(t_cub3d *data)
{
	data->player->player_x = (data->player->player_x * BLOCK_SIZE / PLAYER_SIZE)
		+ (BLOCK_SIZE / PLAYER_SIZE / 2);
	data->player->player_y = (data->player->player_y * BLOCK_SIZE / PLAYER_SIZE)
		+ (BLOCK_SIZE / PLAYER_SIZE / 2);
}

static void	calculate_angle(char player_direction, t_cub3d *data)
{
	if (player_direction == 'E')
		data->player->player_angle = 0.0;
	else if (player_direction == 'N')
		data->player->player_angle = 90.0;
	else if (player_direction == 'W')
		data->player->player_angle = 180.0;
	else if (player_direction == 'S')
		data->player->player_angle = 270.0;
}

void	init_player_position(t_cub3d *data, int x, int y, char **map)
{
	data->player_direction = map[y][x];
	data->player->player_x = x;
	data->player->player_y = y;
	calculate_angle(map[y][x], data);
	data->player->pdx = cos(degree_to_rad(data->player->player_angle));
	data->player->pdy = -sin(degree_to_rad(data->player->player_angle));
}

void	assign_player_map_dimension(t_cub3d *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (check_character(map[y][x], 2))
			{
				data->player_number += 1;
				init_player_position(data, x, y, map);
			}
			x++;
		}
		if ((int)ft_strlen(map[y]) > data->width)
			data->width = (int)ft_strlen(map[y]);
		y++;
	}
	data->height = y;
}
