/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:33 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/08 13:34:36 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_data(t_cub3d *data)
{
	int	i;

	i = 0;
	data->width = 0;
	data->height = 0;
	data->fd = 0;
	data->raw_map = NULL;
	data->map = NULL;
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
