/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:49:03 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/11 15:51:16 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static unsigned int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	set_color_to_floor_ceiling(t_cub3d *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (data->colors[i].name == 'F')
			data->floor_color = rgb_to_int(data->colors[i].rgb[0], \
			data->colors[i].rgb[1], data->colors[i].rgb[2]);
		else if (data->colors[i].name == 'C')
			data->ceil_color = rgb_to_int(data->colors[i].rgb[0], \
			data->colors[i].rgb[1], data->colors[i].rgb[2]);
		i++;
	}
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

static void	init_player_position(t_cub3d *data, int x, int y, char **map)
{
	data->player_direction = map[y][x];
	data->player->player_x = x + 0.5;
	data->player->player_y = y + 0.5;
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
