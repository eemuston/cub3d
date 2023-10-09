/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:38:30 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 15:13:49 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	texture_finder(t_cub3d *data, int direction)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (data->texture[index].identifier == direction)
			break ;
		index++;
	}
	return (index);
}

void	select_texture(t_cub3d *data, double px, double py, int side)
{
	int	direction;

	if (side == 0 && px > 0)
		direction  = texture_finder(data, WEST);
	else if (side == 0 && px < 0)
		direction  = texture_finder(data, EAST);
	else if (side == 1 && py > 0)
		direction  = texture_finder(data, SOUTH);
	else
		direction  = texture_finder(data, NORTH);
	data->selected_texture = data->texture[direction].img;
	data->texture_w = data->texture[direction].width;
	data->texture_h = data->texture[direction].height;
	data->texture_data = data->texture[direction].data;
}
