/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:34:34 by vvu               #+#    #+#             */
/*   Updated: 2023/09/27 17:45:11 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

double	degree_to_rad(double angle)
{
	return (angle * M_PI / 180.0);
}

void	render_background(t_cub3d *data)
{
	int	y;
	int	x;
	int	color;

	color = 0x58ABE5;
	y = -1;
	while (++y < Y)
	{
		x = -1;
		while (++x < X)
		{
			my_mlx_pixel_put(data, x, y, color);
		}
	}
}

void	draw_2d_direction(t_cub3d *data)
{
	t_line	line;
	t_point	p1;
	t_point	p2;

	line.dx = 0;
	p1.p_x = data->player->player_x * PLAYER_SIZE + PLAYER_SIZE / 2;
	p1.p_y = data->player->player_y * PLAYER_SIZE + PLAYER_SIZE / 2;
	p2.p_x = (data->player->player_x * PLAYER_SIZE + PLAYER_SIZE / 2)
		+ data->player->pdx * 10;
	p2.p_y = (data->player->player_y * PLAYER_SIZE + PLAYER_SIZE / 2)
		+ data->player->pdy * 10;
	bresenham(p1, p2, data, line);
}

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
	data->raw_map[(int)(ry / BLOCK_SIZE)][(int)(rx
		/ BLOCK_SIZE)] != '1')
	{
		rx += cos(angle) * distance;
		ry -= sin(angle) * distance;
	}
	if (rx >= 0 && rx < data->width * BLOCK_SIZE && \
		ry >= 0 && ry < data->height * BLOCK_SIZE)
	{
		bresenham((t_point){data->player->pixel_x, data->player->pixel_y},
			(t_point){rx, ry}, data, (t_line){0});
	}
}

void	draw_fov(t_cub3d *data)
{
	double	p_angle;
	double	fov_angle;
	double	angle;

	grid_to_pixel(data);
	p_angle = degree_to_rad(data->player->player_angle);
	fov_angle = degree_to_rad(FOV / 2.0);
	angle = p_angle - fov_angle;
	while (angle <= p_angle + fov_angle)
	{
		draw_ray(data, angle);
		angle += degree_to_rad(1.0);
	}
}

void	render_game(t_cub3d *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	render_background(data);
	draw_2d_map(data);
	draw_2d_player(data);
	draw_2d_direction(data);
	draw_fov(data);
	mlx_put_image_to_window(data->mlx_ptr, \
		data->mlx_window, data->img->img_ptr, 0, 0);
}
