/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:55:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/03 18:56:50 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	draw_ray(t_cub3d *data, double angle)
{
	double	distance;
	double	ray_x;
	double	ray_y;

	distance = 0.1;
	ray_x = data->player->pixel_x;
	ray_y = data->player->pixel_y;
	while (is_in_map(data, ray_x, ray_y) && is_not_wall(data, ray_x, ray_y))
		update_position(&ray_x, &ray_y, angle, distance);
	if (is_in_map(data, ray_x, ray_y))
	{
		dda_algorithm((t_point){data->player->pixel_x, data->player->pixel_y}, \
			(t_point){ray_x, ray_y}, data, (t_line){0});
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
