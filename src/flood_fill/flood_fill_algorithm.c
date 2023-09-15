/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:34:41 by vvu               #+#    #+#             */
/*   Updated: 2023/09/12 18:02:46 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	fill_map_with_x(int x, int y, char ***map, t_cub3d *data)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height)
		return ;
	else
	{
		if (check_character((*map)[y][x], 3) != 0)
			return ;
		(*map)[y][x] = 'X';
		fill_map_with_x(x + 1, y, map, data);
		fill_map_with_x(x - 1, y, map, data);
		fill_map_with_x(x, y + 1, map, data);
		fill_map_with_x(x, y - 1, map, data);
	}
	return ;
}

int	flood_fill(char **raw_map, t_cub3d *data)
{
	char	**temp_map;

	temp_map = NULL;
	if (allocate_temp_map(&temp_map, raw_map, data->height, data->width))
		return (error_in_texture(data, 4));
	fill_map_with_x(data->player_x, data->player_y, &temp_map, data);
	if (check_valid_line(temp_map, 4))
	{
		free_array(temp_map);
		return (error_in_texture(data, 5));
	}
	free_array(temp_map);
	temp_map = NULL;
	return (0);
}