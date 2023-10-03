/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:55:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/03 18:29:31 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	grid_to_pixel(t_cub3d *data)
{
	data->player->pixel_x = (data->player->player_x + 0.5) * PLAYER_SIZE;
	data->player->pixel_y = (data->player->player_y + 0.5) * PLAYER_SIZE;
}

void	draw_ray(t_cub3d *data, double angle)
{
	double	rx;
	double	ry;
	double	distance;

	distance = 0.1;
	rx = data->player->pixel_x;
	ry = data->player->pixel_y;
	while (rx >= 0 && rx < data->width * BLOCK_SIZE && \
		ry >= 0 && ry < data->height * BLOCK_SIZE && \
		data->raw_map[(int)(ry / BLOCK_SIZE)][(int)(rx \
				/ BLOCK_SIZE)] != '1')
	{
		rx += cos(angle) * distance;
		ry -= sin(angle) * distance;
	}
	if (rx >= 0 && rx < data->width * BLOCK_SIZE && \
		ry >= 0 && ry < data->height * BLOCK_SIZE)
	{
		dda_algorithm((t_point){data->player->pixel_x, data->player->pixel_y},
			(t_point){rx, ry},
			data,
			(t_line){0});
	}
}

void	draw_fov(t_cub3d *data)
{
	data->ray->center_angle = degree_to_rad(data->player->player_angle);
	data->ray->half_fov = degree_to_rad(FOV) / 2.0;
	data->ray->start_angle = data->ray->center_angle - data->ray->half_fov;
	data->ray->end_angle = data->ray->center_angle + data->ray->half_fov;
	data->ray->angle_increment = degree_to_rad(0.5);
	grid_to_pixel(data);
	data->ray->angle = data->ray->start_angle;
	while (data->ray->angle <= data->ray->end_angle)
	{
		draw_ray(data, data->ray->angle);
		data->ray->angle += data->ray->angle_increment;
	}
}

// void	draw_fov(t_cub3d *data)
// {
// 	double	p_angle;
// 	double	fov_angle;
// 	double	angle;

// 	grid_to_pixel(data);
// 	p_angle = degree_to_rad(data->player->player_angle);
// 	fov_angle = degree_to_rad(FOV / 2.0);
// 	angle = p_angle - fov_angle;
// 	while (angle <= p_angle + fov_angle)
// 	{
// 		draw_ray(data, angle);
// 		angle += degree_to_rad(0.5);
// 	}
// }
