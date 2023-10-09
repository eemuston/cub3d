/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:06:01 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 19:06:02 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	init_mlx_ray_player(t_cub3d *data)
{
	data->img = ft_calloc(sizeof(t_img), 1);
	data->player = ft_calloc(sizeof(t_player), 1);
	data->ray = ft_calloc(sizeof(t_ray), 1);
	if (!data->img || !data->player || !data->ray)
		return (1);
	data->img->img_ptr = NULL;
	data->mlx_ptr = NULL;
	data->mlx_window = NULL;
	data->player->player_x = 0;
	data->player->player_y = 0;
	return (0);
}

int	init_data(t_cub3d *data)
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
	if (init_mlx_ray_player(data))
		return (error_in_texture(data, 4));
	while (++i < 2)
		data->colors[i].color = NULL;
	i = -1;
	while (++i < 4)
	{
		data->texture[i].path = NULL;
		data->texture[i].identifier = 0;
	}
	return (0);
}
