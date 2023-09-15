/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_zeros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:40:02 by vvu               #+#    #+#             */
/*   Updated: 2023/09/15 15:22:11 by atoof            ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->raw_map[i])
	{
		j = 0;
		while (data->raw_map[i][j] != '\0')
		{
			if (data->raw_map[i][j] == '0')
			{
				if (check_zero(data, i, j) == 1)
				{
					error_in_texture(data, 5);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
