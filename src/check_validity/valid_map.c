/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:27:01 by vvu               #+#    #+#             */
/*   Updated: 2023/09/19 12:32:22 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	check_zero(char **temp_map, t_cub3d *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->width + 2 || y >= data->height + 2)
		return ;
	else
	{
		if (temp_map[y][x] == '1' || temp_map[y][x] == '\0' \
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

static int	assign_temp_map(char ***temp_map, int index, \
					int current, t_cub3d *data)
{
	printf("heiht %d\n", data->height);
	printf("width: %d\n", data->width);
	*temp_map = ft_calloc(sizeof(char *), (data->height + 3));
	if (!(*temp_map))
		return (1);
	while (++index < data->height + 2)
	{
		(*temp_map)[index] = ft_calloc(sizeof(char),(data->width + 3));
		if (!((*temp_map)[index]))
			return (1);
	}
	index = -1;
	while (++index < data->height + 2)
	{
		current = -1;
		while (++current < data->width + 2)
			(*temp_map)[index][current] = '-';
		(*temp_map)[index][current] = '\0';
	}
	(*temp_map)[index] = NULL;
	return (0);
}

static int	check_map_zeros_player(t_cub3d *data, int index, int current)
{
	char	**temp_map;
	int i = 0;

	while (data->raw_map[i])
	{
		printf("%s\n", data->raw_map[i]);
		i++;
	}
	temp_map = NULL;
	if (assign_temp_map(&temp_map, index, current, data))
		return (error_in_texture(data, 4));
	i = 0;
	while (i < data->height + 2)
	{
		printf("%s\n", temp_map[i]);
		i++;
	}
	if (!temp_map)
		return (error_in_texture(data, 4));
	index = -1;
	while (++index < data->height)
	{
		current = 0;
		while (current < (int)ft_strlen(data->raw_map[index]))
		{
			temp_map[index + 1][current + 1] = \
			data->raw_map[index][current];
			current++;
		}
	}
	printf("\n");
	i = 0;
	while (i < data->height + 2)
	{
		printf("%s\n", temp_map[i]);
		i++;
	}
	check_zero(temp_map, data, 0, 0);
	free_array(temp_map);
	if (data->found_zero == 1)
		return (error_in_texture(data, 9));
	return (0);
}

int	valid_map(t_cub3d *data)
{
	if (check_map_zeros_player(data, -1, 0))
		return (1);
	return (0);
}
