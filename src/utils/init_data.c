/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:33 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/21 16:54:16 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	init_player(t_cub3d *data)
{
	data->player->player_x = (data->player->player_x * BLOCK_SIZE / \
	PLAYER_SIZE) + PLAYER_SIZE / 2;
	data->player->player_y = (data->player->player_y * BLOCK_SIZE / \
	PLAYER_SIZE) + PLAYER_SIZE / 2;
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
	data->player_number = 0;
	data->raw_map = NULL;
	data->map = NULL;
	init_mlx_ptr(data);
	//TODO:protect malloc
	data->ray = ft_calloc(sizeof(t_ray), 1);
	data->player = ft_calloc(sizeof(t_player), 1);
	data->player->player_x = 0;
	data->player->player_y = 0;
	while (++i < 2)
		data->colors[i].color = NULL;
	i = -1;
	while (++i < 4)
	{
		data->texture[i].path = NULL;
		data->texture[i].identifier = 0;
	}
}
