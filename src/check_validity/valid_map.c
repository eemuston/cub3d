/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:27:01 by vvu               #+#    #+#             */
/*   Updated: 2023/09/13 12:31:58 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	player_surround_by_1_0(int x, int y, int height, char **raw_map)
{
	if (y == 0 || y == height - 1)
		return (1);
	if (check_character(raw_map[y][x], 2))
	{
		if (!check_character(raw_map[y - 1][x], 4))
			return (1);
		if (!check_character(raw_map[y + 1][x], 4))
			return (1);
		if (!check_character(raw_map[y][x - 1], 4))
			return (1);
		if (!check_character(raw_map[y][x + 1], 4))
			return (1);
	}
	return (0);
}

int	valid_map(t_cub3d *data, char **raw_map)
{
	char	**temp_map;

	temp_map = NULL;
	if (allocate_temp_map(&temp_map, raw_map, data->height, data->width))
		return (error_in_texture(data, 4));
	if (player_surround_by_1_0(data->player_x, data->player_y, data->height, \
								raw_map))
	{
		free_array(temp_map);
		return (error_in_texture(data, 5));
	}
	free_array(temp_map);
	temp_map = NULL;
	if (check_map_zeros(data))
		return (1);
	return (0);
}
