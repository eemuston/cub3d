/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/10/13 12:42:17 by atoof            ###   ########.fr       */
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
