/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_zeros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:40:02 by vvu               #+#    #+#             */
/*   Updated: 2023/09/18 15:55:54 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	check_zero(t_cub3d *data, int y, int x)
{
	if (y == 0 || y == data->height - 1)
		return (1);
	if (data->raw_map[i][j] == '0' || data->raw_map[i][j] == ' ')
	{
		if (data->raw_map[i + 1][j] && \
		check_character(data->raw_map[i + 1][j], 5))
			return (1);
		if (data->raw_map[i - 1][j] && \
		check_character(data->raw_map[i - 1][j], 5))
			return (1);
		if (data->raw_map[i][j + 1] && \
		check_character(data->raw_map[i][j + 1], 5))
			return (1);
		if (data->raw_map[i][j - 1] && \
		check_character(data->raw_map[i][j - 1], 5))
			return (1);
	}
	return (0);
}

int	check_map_zeros(t_cub3d *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->raw_map[y])
	{
		x = 0;
		while (data->raw_map[y][x] != '\0')
		{
			if (data->raw_map[i][j] == '0' || data->raw_map[i][j] == ' ')
			{
				if (check_zero(data, y, x) == 1)
				{
					error_in_texture(data, 5);
					return (1);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}
