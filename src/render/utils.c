/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:38:30 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 18:50:49 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

double	fix_angle(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	horizontal_vertical(t_cub3d *data)
{
	if (data->ray->ray_dir.p_x < 0)
	{
		data->ray->step_x = -1;
		data->ray->side_dist_x = (data->ray->ray_pos.p_x - \
			data->ray->map_x) * data->ray->delta_dist_x;
	}
	else
	{
		data->ray->step_x = 1;
		data->ray->side_dist_x = (data->ray->map_x + 1.0 - \
			data->ray->ray_pos.p_x) * data->ray->delta_dist_x;
	}
	if (data->ray->ray_dir.p_y < 0)
	{
		data->ray->step_y = -1;
		data->ray->side_dist_y = (data->ray->ray_pos.p_y - \
			data->ray->map_y) * data->ray->delta_dist_y;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->side_dist_y = (data->ray->map_y + 1.0 - \
			data->ray->ray_pos.p_y) * data->ray->delta_dist_y;
	}
}

void	hit_wall(t_cub3d *data)
{
	while (!data->ray->hit)
	{
		if (data->ray->side_dist_x < data->ray->side_dist_y)
		{
			data->ray->side_dist_x += data->ray->delta_dist_x;
			data->ray->map_x += data->ray->step_x;
			data->ray->side = 0;
		}
		else
		{
			data->ray->side_dist_y += data->ray->delta_dist_y;
			data->ray->map_y += data->ray->step_y;
			data->ray->side = 1;
		}
		if (data->raw_map[data->ray->map_y][data->ray->map_x] == '1')
			data->ray->hit = 1;
	}
}
