/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:33 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/06 16:38:32 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_data(t_cub3d *data)
{
	int i;

	i = 0;
	data->width = 0;
	data->height = 0;
	data->fd = 0;
	while (i < 4)
	{
		data->texture[i].path = NULL;
		data->texture[i].identifier = 0;
		i++;
	}
}
