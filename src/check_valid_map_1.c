/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:36:29 by vvu               #+#    #+#             */
/*   Updated: 2023/09/12 11:13:22 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

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

static int	allocate_temp_map(char ***temp_map, char **raw_map, \
								int height, int width)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	*temp_map = ft_calloc(sizeof(char *), height + 1);
	if (!(*temp_map))
		return (1);
	while (raw_map[y] != NULL)
	{
		(*temp_map)[y] = ft_calloc(sizeof(char), width + 1);
		if (!((*temp_map)[y]))
			return (1);
		y++;
	}
	(*temp_map)[y] = NULL;
	while (i < height)
	{
		ft_memmove((*temp_map)[i], raw_map[i], ft_strlen(raw_map[i]));
		i++;
	}
	return (0);
}

static int	flood_fill(char **raw_map, t_cub3d *data)
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
	return (0);
}

static void	assign_player_dimension(t_cub3d *data, char **map, int *temp)
{
	int	index;
	int	current;

	index = 0;
	while (map[index] != NULL)
	{
		current = 0;
		while (map[index][current] != '\0')
		{
			if (check_character(map[index][current], 2))
			{
				data->player += 1;
				data->player_direction = map[index][current];
				data->player_x = current;
				data->player_y = index;
			}
			current++;
		}
		*temp = ft_strlen(map[index]);
		if (*temp > data->width)
			data->width = *temp;
		index++;
	}
	data->height = index;
}

int	check_amount_player(char **map, int index, t_cub3d *data)
{
	int	temp;

	temp = 0;
	if (map[index] != NULL)
	{
		assign_player_dimension(data, map, &temp);
		if (data->player > 1)
			return (error_in_texture(data, 7));
		if (flood_fill(data->raw_map, data))
			return (1);
	}
	return (0);
}
