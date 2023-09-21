/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:49:03 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/21 16:59:03 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static double	calculate_angle(char player_direction)
{
	double	angle;

	if (player_direction == 'E')
		angle = 0.0;
	else if (player_direction == 'N')
		angle = 90.0;
	else if (player_direction == 'W')
		angle = 180.0;
	else if (player_direction == 'S')
		angle = 270.0;
	else
		angle = -1.0;
	return (angle);
}

void	init_player_position(t_cub3d *data, int x, int y, char **map)
{
	data->player_direction = map[y][x];
	data->player->player_x = x;
	data->player->player_y = y;
	data->player->player_angle = calculate_angle(map[y][x]);
	data->ray->dir_x = cos(data->player->player_angle);
	data->ray->dir_y = sin(data->player->player_angle);
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
