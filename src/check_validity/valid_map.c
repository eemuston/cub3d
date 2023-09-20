/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:27:01 by vvu               #+#    #+#             */
/*   Updated: 2023/09/19 18:41:36 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	check_zero(char **temp_map, t_cub3d *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->width + 2 || y >= data->height + 2)
		return ;
	else
	{
		if (temp_map[y][x] == '1' || temp_map[y][x] == '\0'
			|| temp_map[y][x] == 'X')
			return ;
		if (temp_map[y][x] == '0' || check_character(temp_map[y][x], 2))
			data->found_zero = 1;
		temp_map[y][x] = 'X';
		check_zero(temp_map, data, x + 1, y);
		check_zero(temp_map, data, x - 1, y);
		check_zero(temp_map, data, x, y + 1);
		check_zero(temp_map, data, x, y - 1);
	}
}

static void	fill_temp_map(char ***temp_map, int height, int width, \
t_cub3d *data)
{
	int	index;
	int	current;

	index = 0;
	while (index < height)
	{
		current = -1;
		while (++current < width)
			(*temp_map)[index][current] = '-';
		index++;
	}
	index = -1;
	while (++index < data->height)
	{
		current = 0;
		while (current < (int)ft_strlen(data->raw_map[index]))
		{
			(*temp_map)[index + 1][current + 1] = data->raw_map[index][current];
			current++;
		}
	}
}

static int	flood_fill_outside_map(t_cub3d *data)
{
	char	**temp_map;
	int		index;

	index = 0;
	temp_map = NULL;
	temp_map = ft_calloc(sizeof(char *), data->height + 3);
	if (!temp_map)
		return (error_in_texture(data, 4));
	while (index < data->height + 2)
	{
		temp_map[index] = ft_calloc(sizeof(char), data->width + 3);
		if (!temp_map[index])
			return (error_in_texture(data, 4));
		index++;
	}
	fill_temp_map(&temp_map, data->height + 2, data->width + 2, data);
	check_zero(temp_map, data, 0, 0);
	free_array(temp_map);
	if (data->found_zero == 1)
		return (error_in_texture(data, 9));
	return (0);
}

int	valid_map(t_cub3d *data)
{
	if (flood_fill_inside_map(data->raw_map, data))
		return (1);
	if (flood_fill_outside_map(data))
		return (1);
	return (0);
}
