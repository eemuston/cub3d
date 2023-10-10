/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:28:04 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 18:30:26 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	texture_finder(t_cub3d *data, int direction)
{
	int	index;

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
		direction = texture_finder(data, WEST);
	else if (side == 0 && px < 0)
		direction = texture_finder(data, EAST);
	else if (side == 1 && py > 0)
		direction = texture_finder(data, NORTH);
	else
		direction = texture_finder(data, SOUTH);
	data->selected_texture = data->texture[direction].img;
	data->texture_w = data->texture[direction].width;
	data->texture_h = data->texture[direction].height;
	data->texture_data = data->texture[direction].data;
}

static void	line_too_long(t_cub3d *data, int y)
{
	if (data->ray->side == 0)
		data->ray->wall_x = data->player->player_y + \
		data->ray->wall_distance * data->ray->ray_dir.p_y;
	else
		data->ray->wall_x = data->player->player_x + \
		data->ray->wall_distance * data->ray->ray_dir.p_x;
	data->ray->wall_x -= floor(data->ray->wall_x);
	select_texture(data, data->ray->ray_dir.p_x, \
	data->ray->ray_dir.p_y, data->ray->side);
	data->ray->texture_x = (int)(data->ray->wall_x * (double)data->texture_w);
	if (data->ray->side == 0 && data->ray->ray_dir.p_x > 0)
		data->ray->texture_x = data->texture_w - data->ray->texture_x - 1;
	if (data->ray->side == 1 && data->ray->ray_dir.p_y < 0)
		data->ray->texture_x = data->texture_w - data->ray->texture_x - 1;
	data->ray->texture_offset = y * 256 - HEIGHT * 128 + \
	data->ray->wall_height * 128;
	data->ray->texture_y = ((data->ray->texture_offset * data->texture_h) \
	/ data->ray->wall_height) / 256;
	data->ray->color = data->texture_data[data->texture_w * data->ray->texture_y
		+ data->ray->texture_x];
}

void	draw_walls(t_cub3d *data, int screen_x)
{
	int	y;

	data->ray->wall_height = (int)(HEIGHT / data->ray->wall_distance);
	data->ray->draw_start = -data->ray->wall_height / 2 + HEIGHT / 2;
	if (data->ray->draw_start < 0)
		data->ray->draw_start = 0;
	data->ray->draw_end = data->ray->wall_height / 2 + HEIGHT / 2;
	if (data->ray->draw_end >= HEIGHT)
		data->ray->draw_end = HEIGHT - 1;
	y = data->ray->draw_start;
	while (y < data->ray->draw_end)
	{
		line_too_long(data, y);
		my_mlx_pixel_put(data, screen_x, y, data->ray->color);
		y++;
	}
}
