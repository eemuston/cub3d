/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:24:51 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/11 14:56:55 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	my_mlx_pixel_put(t_cub3d *data, double width, \
						double height, unsigned int color)
{
	char	*dst;
	int		y;
	int		x;

	x = round(width);
	y = round(height);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	dst = data->img->addr + (y * data->img->line_length + \
	x * (data->img->bits_per_pixel / 8));
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
		*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_mini(t_cub3d *data, double width \
		, double height, unsigned int color)
{
	char	*dst;
	int		y;
	int		x;

	x = round(width);
	y = round(height);
	data->mini_img->addr = mlx_get_data_addr(data->mini_img->img_ptr,
			&data->mini_img->bits_per_pixel, &data->mini_img->line_length,
			&data->mini_img->endian);
	dst = data->mini_img->addr + (y * data->mini_img->line_length + \
	x * (data->mini_img->bits_per_pixel / 8));
	if ((x >= 0 && x < MINI_WIDTH) && (y >= 0 && y < MINI_HEIGHT))
		*(unsigned int *)dst = color;
}
