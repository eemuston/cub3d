/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:24:51 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/18 14:32:16 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

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

void	my_mlx_pixel_put(t_cub3d *data, int x, int y, unsigned int color)
{
	char	*dst;

	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	dst = data->img->addr + (y * data->img->line_length + \
	x * (data->img->bits_per_pixel
				/ 8));
	if ((x >= 0 && x < X) && (y >= 0 && y < Y))
		*(unsigned int *)dst = color;
}

// int	slop(int x1, int x2)
// {
// 	if (x1 < x2)
// 		return (1);
// 	else
// 		return (-1);
// }

// unsigned int	ft_abs(int x)
// {
// 	if (x < 0)
// 		x = -x;
// 	return (x);
// }

// void	ft_draw(t_cub3d *data)
// {
// 	tmp.p1.y = -1;
// 	while (++tmp.p1.y < data->height)
// 	{
// 		tmp.p1.x = -1;
// 		while (++tmp.p1.x < data->width)
// 		{
// 			if (tmp.p1.x < data->width - 1)
// 			{
// 				tmp.p2.x = tmp.p1.x + 1;
// 				tmp.p2.y = tmp.p1.y;
// 				bresenham(tmp, data);
// 			}
// 			if (tmp.p1.y < data->height - 1)
// 			{
// 				tmp.p2.y = tmp.p1.y + 1;
// 				tmp.p2.x = tmp.p1.x;
// 				bresenham(tmp, data);
// 			}
// 		}
// 	}
// }
