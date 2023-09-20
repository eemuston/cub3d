/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:33 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/20 18:46:48 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	init_player(t_cub3d *data)
{
	data->player_x = (data->player_x * BLOCK_SIZE / \
	PLAYER_SIZE) + PLAYER_SIZE / 2;
	data->player_y = (data->player_y * BLOCK_SIZE / \
	PLAYER_SIZE) + PLAYER_SIZE / 2;
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
