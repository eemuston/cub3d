/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:27:01 by vvu               #+#    #+#             */
/*   Updated: 2023/09/20 11:00:16 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	find_space_in_map(char **temp_map, t_cub3d *data, \
									int index, int current)
{
	if (allocate_temp_map(&temp_map, data->raw_map, data->height, data->width))
		return (error_in_texture(data, 4));
	while (++index < data->height)
	{
		current = -1;
		while (++current < data->width)
		{
			if (temp_map[index][current] == 32)
			{
				if (check_character(temp_map[index + 1][current], 5) ||
					check_character(temp_map[index - 1][current], 5) ||
					check_character(temp_map[index][current + 1], 5) ||
					check_character(temp_map[index][current - 1], 5))
				{
					free_array(temp_map);
					return (error_in_texture(data, 10));
				}
			}
		}
	}
	free_array(temp_map);
	return (0);
}

int	valid_map(t_cub3d *data)
{
	char	**temp_map;

	temp_map = NULL;
	if (flood_fill_inside_map(temp_map, data))
		return (1);
	if (flood_fill_outside_map(temp_map, data))
		return (1);
	if (find_space_in_map(temp_map, data, -1, -1))
		return (1);
	return (0);
}
