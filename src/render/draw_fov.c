/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:55:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/09 15:02:46 by vvu              ###   ########.fr       */
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

void	cast_ray(t_cub3d *data, double ray_angle, int screen_x)
{
	t_point	ray_pos;
	t_point	ray_dir;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_distance;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	ca;
	int		wall_height;
	int		draw_start;
	int		draw_end;
	double	wallX;
	int		textureX;
	int		d;
	int		textureY;
	int		color;
	hit = 0;
	hit = 0;
	ray_pos.p_x = data->player->player_x;
	ray_pos.p_y = data->player->player_y;
	ray_dir.p_x = cos(ray_angle);
	ray_dir.p_y = -sin(ray_angle);
	map_x = (int)ray_pos.p_x;
	map_y = (int)ray_pos.p_y;
	delta_dist_x = fabs(1 / ray_dir.p_x);
	delta_dist_y = fabs(1 / ray_dir.p_y);
	if (ray_dir.p_x < 0)
	{
		step_x = -1;
		side_dist_x = (ray_pos.p_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - ray_pos.p_x) * delta_dist_x;
	}
	if (ray_dir.p_y < 0)
	{
		step_y = -1;
		side_dist_y = (ray_pos.p_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - ray_pos.p_y) * delta_dist_y;
	}
	while (!hit)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (data->raw_map[map_y][map_x] == '1')
			hit = 1;
	}
	if (side == 0)
		wall_distance = (map_x - ray_pos.p_x + (1 - step_x) / 2) / ray_dir.p_x;
	else
		wall_distance = (map_y - ray_pos.p_y + (1 - step_y) / 2) / ray_dir.p_y;
	ca = fix_angle(degree_to_rad(data->player->player_angle) - ray_angle);
	wall_distance = wall_distance * cos(ca);
	wall_height = (int)(HEIGHT / wall_distance);
	draw_start = -wall_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = wall_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	for (int y = draw_start; y < draw_end; y++)
	{
		if (side == 0)
			wallX = data->player->player_y + wall_distance * ray_dir.p_y;
		else
			wallX = data->player->player_x + wall_distance * ray_dir.p_x;
		wallX -= floor(wallX);
		select_texture(data, ray_dir.p_x, ray_dir.p_y, side);
		textureX = (int)(wallX * (double)data->texture_w);
		if (side == 0 && ray_dir.p_x > 0)
			textureX = data->texture_w - textureX - 1;
		if (side == 1 && ray_dir.p_y < 0)
			textureX = data->texture_w - textureX - 1;
		d = y * 256 - HEIGHT * 128 + wall_height * 128;
		textureY = ((d * data->texture_h) / wall_height) / 256;
		color = data->texture_data[data->texture_w * textureY
			+ textureX];
		my_mlx_pixel_put(data, screen_x, y, color);
	}
}

void	draw_fov(t_cub3d *data)
{
	double	fov;
	double	ray_angle;
	double	delta_angle;

	fov = degree_to_rad(60);
	ray_angle = degree_to_rad(data->player->player_angle) + fov / 2;
	delta_angle = fov / WIDTH;
	for (int x = 0; x < WIDTH; x++)
	{
		cast_ray(data, ray_angle, x);
		ray_angle -= delta_angle;
	}
}
