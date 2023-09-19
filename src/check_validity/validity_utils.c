/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:21:10 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/19 12:27:08 by vvu              ###   ########.fr       */
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
		return (c == '1');
	else if (flag == 5)
		return (c != '1' && c != '0' && c != 'W' && c != 'S' && c != 'E' && \
				c != 'N' && c != ' ');
	else if (flag == 6)
		return ((c >= 9 && c <= 13) || c == 32 || ft_isdigit(c));
	else if (flag == 7)
		return (c == '1' || c == '0' || c == 32);
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

int	not_valid_line(char *current)
{
	int	index;
	int	len;

	index = 0;
	len = ft_strlen(current);
	if (len == 1 && current[index] == '\n')
		return (1);
	while (current[index] == 32 \
	|| (current[index] >= 9 && current[index] <= 13))
	{
		index++;
		if (current[index] == '\n' || current[index] == '\0')
			return (1);
	}
	while (current[index] != '\0')
	{
		if (current[index] == '\n')
			index++;
		else if (!check_character(current[index], 1))
			return (1);
		if (current[index] != '\0')
			index++;
	}
	return (0);
}
