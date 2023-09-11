/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:36:29 by vvu               #+#    #+#             */
/*   Updated: 2023/09/11 17:18:05 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	check_valid_map(int x, int y, char ***map, t_cub3d *data)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height \
	|| check_character((*map)[y][x], 3))
		return ;
	else
	{
		if (check_character((*map)[y][x], 3) != 0)
			return ;
		(*map)[y][x] = 'X';
		check_valid_map(x + 1, y, map, data);
		check_valid_map(x - 1, y, map, data);
		check_valid_map(x, y + 1, map, data);
		check_valid_map(x, y - 1, map, data);
	}
	return ;
}

static int	flood_fill(int y, char **raw_map, t_cub3d *data)
{
	char	**temp_map;
	int		i;

	i = 0;
	temp_map = ft_calloc(sizeof(char *), data->height + 1);
	if (!temp_map)
		return (error_in_texture(data, 4));
	while (raw_map[y] != NULL)
	{
		temp_map[y] = ft_strdup(raw_map[y]);
		if (!temp_map[y])
			return (error_in_texture(data, 4));
		y++;
	}
	check_valid_map(data->player_x, data->player_y, &temp_map, data);
	printf("\nafter fllod fill\n");
	while (temp_map[i] != NULL)
	{
		if (i + 1 < 10)
			printf("i: %d  %s\n", i + 1, temp_map[i]);
		else
			printf("i: %d %s\n", i + 1, temp_map[i]);
		i++;
	}
	if (temp_map)
		free_array(temp_map);
	return (0);
}

int	check_amount_player(char **map, int index, int current, t_cub3d *data)
{
	int	temp;

	temp = 0;
	if (map[index] != NULL)
	{
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
			temp = ft_strlen(map[index]);
			if (temp > data->width)
				data->width = temp;
			index++;
		}
		data->height = index;
		if (data->player > 1)
			return (error_in_texture(data, 7));
		flood_fill(0, data->raw_map, data);
		//free_array(data->raw_map);
	}
	return (0);
}
