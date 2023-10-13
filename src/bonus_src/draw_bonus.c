/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:06:39 by atoof             #+#    #+#             */
/*   Updated: 2023/10/13 14:06:42 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d_bonus.h"

void	render_background_mini(t_cub3d *data)
{
	int	color;
	int	y;
	int	x;

	color = 0x0000FF;
	y = 0;
	while (y < MINI_HEIGHT - 1)
	{
		x = 0;
		while (x < MINI_WIDTH - 1)
		{
			my_mlx_pixel_put_mini(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_2d_direction(t_cub3d *data)
{
	t_line	line;
	t_point	p1;
	t_point	p2;

	line.dx = 0;
	p1.p_x = (MINI_WIDTH / 2) + PLAYER_SIZE / 2;
	p1.p_y = (MINI_HEIGHT / 2) + PLAYER_SIZE / 2;
	p2.p_x = (MINI_WIDTH / 2) + PLAYER_SIZE / 2
		+ data->player->pdx * 10;
	p2.p_y = (MINI_HEIGHT / 2) + PLAYER_SIZE / 2
		+ data->player->pdy * 10;
	dda_algorithm(p1, p2, data, line);
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
