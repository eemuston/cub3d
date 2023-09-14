/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_zeros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:40:02 by vvu               #+#    #+#             */
/*   Updated: 2023/09/14 08:59:04 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	check_zero(t_cub3d *data, int y, int x)
{
	if (y == 0 || y == data->height - 1)
		return (1);
	if (data->raw_map[y][x] == '0')
	{
		if (check_character(data->raw_map[y + 1][x], 5))
			return (1);
		if (check_character(data->raw_map[y - 1][x], 5))
			return (1);
		if (check_character(data->raw_map[y][x + 1], 5))
			return (1);
		if (check_character(data->raw_map[y][x - 1], 5))
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
			if (data->raw_map[y][x] == '0')
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
