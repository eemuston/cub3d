/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:21:10 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/12 16:19:47 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	check_character(char c, int flag)
{
	if (flag == 1)
		return ((c == '1' || c == 32 || (c >= 9 && c <= 13) || c == '0' || \
				c == 'W' || c == 'S' || c == 'E' || c == 'N'));
	else if (flag == 2)
		return (c == 'W' || c == 'S' || c == 'E' || c == 'N');
	else if (flag == 3)
		return (c == 32 || (c >= 9 && c <= 13) || c == 'X' || c == '\0');
	else if (flag == 4)
		return (c == '1' || c == '0');
	else if (flag == 5)
		return (c != '1' && c != '0' && c != 'W' && c != 'S' && c != 'E' && \
				c != 'N');
	return (0);
}

int	check_amount_player(char **map, int index, t_cub3d *data)
{
	int	temp;

	temp = 0;
	if (map[index] != NULL)
	{
		assign_player_map_dimension(data, map, &temp);
		if (data->player > 1 || data->player == 0)
			return (error_in_texture(data, 7));
	}
	return (0);
}

static int	check_zero(t_cub3d *data, int i, int j)
{
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
