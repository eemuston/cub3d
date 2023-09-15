/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:33 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/15 14:58:07 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	init_data(t_cub3d *data)
{
	int	i;

	i = 0;
	data->width = 0;
	data->height = 0;
	data->fd = 0;
	data->player = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->player_direction = 'a';
	data->raw_map = NULL;
	data->map = NULL;
	data->img = malloc(sizeof(t_img) * 1);
	while (i < 2)
	{
		data->colors[i].color = NULL;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		data->texture[i].path = NULL;
		data->texture[i].identifier = 0;
		i++;
	}
}
