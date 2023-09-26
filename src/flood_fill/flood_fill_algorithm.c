/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:34:41 by vvu               #+#    #+#             */
/*   Updated: 2023/09/26 13:18:59 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	fill_map_with_x(int x, int y, char ***map, t_cub3d *data)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height)
		return ;
	else
	{
		if (check_character((*map)[y][x], 4))
			return ;
		(*map)[y][x] = 'X';
		fill_map_with_x(x + 1, y, map, data);
		fill_map_with_x(x - 1, y, map, data);
		fill_map_with_x(x, y + 1, map, data);
		fill_map_with_x(x, y - 1, map, data);
	}
	return ;
}

int	flood_fill_inside_map(char **temp_map, t_cub3d *data)
{
	if (allocate_temp_map(&temp_map, data->raw_map, data->height, data->width))
		return (error_in_texture(data, 4));
	fill_map_with_x(data->player->player_x, \
					data->player->player_y, &temp_map, data);
	if (check_valid_line(temp_map, 3))
	{
		free_array(temp_map);
		return (error_in_texture(data, 11));
	}
	free_array(temp_map);
	temp_map = NULL;
	return (0);
}

static void	surrounded_by_wall(char **temp_map, t_cub3d *data, int x, int y)
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
		surrounded_by_wall(temp_map, data, x + 1, y);
		surrounded_by_wall(temp_map, data, x - 1, y);
		surrounded_by_wall(temp_map, data, x, y + 1);
		surrounded_by_wall(temp_map, data, x, y - 1);
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

int	flood_fill_outside_map(char	**temp_map, t_cub3d *data)
{
	int	index;

	index = 0;
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
	surrounded_by_wall(temp_map, data, 0, 0);
	free_array(temp_map);
	if (data->found_zero == 1)
		return (error_in_texture(data, 9));
	return (0);
}
