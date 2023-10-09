/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_zeros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:04:34 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 19:04:35 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	check_zero(t_cub3d *data, int i, int j)
{
	if (i == 0 || i == data->height - 1)
		return (1);
	if (data->raw_map[i][j] == '0')
	{
		if (check_character(data->raw_map[i + 1][j], 5))
			return (1);
		if (check_character(data->raw_map[i - 1][j], 5))
			return (1);
		if (check_character(data->raw_map[i][j + 1], 5))
			return (1);
		if (check_character(data->raw_map[i][j - 1], 5))
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
