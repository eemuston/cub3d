/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:45:33 by atoof             #+#    #+#             */
/*   Updated: 2023/10/03 18:48:06 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	grid_to_pixel(t_cub3d *data)
{
	data->player->pixel_x = (data->player->player_x + 0.5) * PLAYER_SIZE;
	data->player->pixel_y = (data->player->player_y + 0.5) * PLAYER_SIZE;
}

bool	is_in_map(t_cub3d *data, double x, double y)
{
	return (x >= 0 && x < data->width * BLOCK_SIZE \
		&& y >= 0 && y < data->height * BLOCK_SIZE);
}

bool	is_not_wall(t_cub3d *data, double x, double y)
{
	return (data->raw_map[(int)(y / BLOCK_SIZE)][(int)(x / BLOCK_SIZE)] != '1');
}

void	update_position(double *x, double *y, double angle, double distance)
{
	*x += cos(angle) * distance;
	*y -= sin(angle) * distance;
}
