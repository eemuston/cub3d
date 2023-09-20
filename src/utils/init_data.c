/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:33 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/20 15:49:37 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static double	calculate_angle(char player_direction)
{
	double	angle;

	if (player_direction == 'E')
		angle = 0.0;
	else if (player_direction == 'N')
		angle = 90.0;
	else if (player_direction == 'W')
		angle = 180.0;
	else if (player_direction == 'S')
		angle = 270.0;
	else
		angle = -1.0;
	return (angle);
}

static void	init_player(t_cub3d *data)
{
	data->player_x = (data->player_x * BLOCK_SIZE /
						PLAYER_SIZE) +
		PLAYER_SIZE / 2;
	data->player_y = (data->player_y * BLOCK_SIZE /
						PLAYER_SIZE) +
		PLAYER_SIZE / 2;
	data->pdx = PLAYER_SIZE / 2;
	data->pdy = PLAYER_SIZE / 2;
}

static void	init_mlx_ptr(t_cub3d *data)
{
	data->img = malloc(sizeof(t_img) * 1);
	data->img->img_ptr = NULL;
	data->mlx_ptr = NULL;
	data->mlx_window = NULL;
}

void	init_data(t_cub3d *data)
{
	int	i;

	i = -1;
	data->found_zero = 0;
	data->width = 0;
	data->height = 0;
	data->fd = 0;
	data->player = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->raw_map = NULL;
	data->map = NULL;
	init_player(data);
	init_mlx_ptr(data);
	data->ray = ft_calloc(sizeof(t_ray), 1);
	while (++i < 2)
		data->colors[i].color = NULL;
	i = -1;
	while (++i < 4)
	{
		data->texture[i].path = NULL;
		data->texture[i].identifier = 0;
	}
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
				data->player_angle = calculate_angle(map[index][current]);
				data->ray->dir_x = cos(data->player_angle);
				data->ray->dir_y = sin(data->player_angle);
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
