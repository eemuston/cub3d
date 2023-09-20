/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:39:03 by vvu               #+#    #+#             */
/*   Updated: 2023/09/19 17:03:53 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static double	calculate_angle(char player_direction)
{
	double	angle;

	if (player_direction == 'N')
		angle = 0.0;
	else if (player_direction == 'E')
		angle = 90.0;
	else if (player_direction == 'S')
		angle = 180.0;
	else if (player_direction == 'W')
		angle = 270.0;
	else
		angle = -1.0;
	return (angle);
}

int	allocate_temp_map(char ***temp_map, char **raw_map, int height, int width)
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

int	check_valid_line(char **map, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (check_character(map[i][j], flag))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	assign_player_map_dimension(t_cub3d *data, char **map, int *temp)
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
				data->pa = calculate_angle(map[index][current]);
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
