/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:55:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/10 16:32:41 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	shortest_distance(t_cub3d *data, double ray_angle)
{
	double	ca;

	if (data->ray->side == 0)
		data->ray->wall_distance = (data->ray->map_x - \
		data->ray->ray_pos.p_x + (1 - data->ray->step_x) / 2) / \
		data->ray->ray_dir.p_x;
	else
		data->ray->wall_distance = (data->ray->map_y - \
		data->ray->ray_pos.p_y + (1 - data->ray->step_y) / 2) / \
		data->ray->ray_dir.p_y;
	ca = fix_angle(degree_to_rad(data->player->player_angle) - ray_angle);
	data->ray->wall_distance = data->ray->wall_distance * cos(ca);
}

static void	init_ray(t_cub3d *data, double ray_angle)
{
	data->ray->hit = 0;
	data->ray->ray_pos.p_x = data->player->player_x;
	data->ray->ray_pos.p_y = data->player->player_y ;
	data->ray->ray_dir.p_x = cos(ray_angle);
	data->ray->ray_dir.p_y = -sin(ray_angle);
	data->ray->map_x = (int)data->ray->ray_pos.p_x;
	data->ray->map_y = (int)data->ray->ray_pos.p_y;
	data->ray->delta_dist_x = fabs(1 / data->ray->ray_dir.p_x);
	data->ray->delta_dist_y = fabs(1 / data->ray->ray_dir.p_y);
}

static void	ray_calculation(t_cub3d *data, double ray_angle, int screen_x)
{
	init_ray(data, ray_angle);
	horizontal_vertical(data);
	hit_wall(data);
	shortest_distance(data, ray_angle);
	draw_walls(data, screen_x);
}

void	ray_casting(t_cub3d *data)
{
	double	fov;
	double	ray_angle;
	double	delta_angle;
	int		x;

	x = 0;
	fov = degree_to_rad(60);
	ray_angle = degree_to_rad(data->player->player_angle) + fov / 2;
	delta_angle = fov / WIDTH;
	while (x < WIDTH)
	{
		ray_calculation(data, ray_angle, x);
		ray_angle -= delta_angle;
		x++;
	}
}
