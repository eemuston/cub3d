/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/09/18 09:33:22 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	render_background(t_cub3d *data)
{
	int	y;
	int	x;
	int	color;
<<<<<<<<< Temporary merge branch 1

	color = 0x58ABE5;
	y = -1;
	while (++y < Y)
	{
		x = -1;
		while (++x < X)
		{
			my_mlx_pixel_put(data, x, y, color);
=========
	int	block_x;

	block_y = 0;
	if (c == '1')
		color = data->color[1];
	else if (c == '0')
		color = data->color[0];
	while (block_y < 10 - 1)
	{
		block_x = 0;
		while (block_x < 10 - 1)
		{
			mlx_pixel_put(data->mlx, data->mlx_window, x * 10 + block_x, \
			y * 10 + block_y, color);
			block_x++;
		}
	}
}

<<<<<<<<< Temporary merge branch 1
void	render_map(t_cub3d *data, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < BLOCK_SIZE - 1)
	{
		j = -1;
		while (++j < BLOCK_SIZE - 1)
			my_mlx_pixel_put(data, x + j, y + i, color);
	}
}

static void	creat_player(t_cub3d *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < PLAYER_SIZE)
	{
		j = -1;
		while (++j < PLAYER_SIZE)
		{
			my_mlx_pixel_put(data, x + j, y + i, color);
=========
void	draw_player(t_cub3d *data)
{
	int	block_x;

	block_y = 0;
	while (block_y < 5)
	{
		block_x = 0;
		while (block_x < 5)
		{
			mlx_pixel_put(data->mlx, data->mlx_window, data->player_x * 5 \
			+ block_x, data->player_y * 5 + block_y, data->color[2]);
			block_x++;
		}
		block_y++;
	}

}

<<<<<<<<< Temporary merge branch 1
void	render_2d_map(t_cub3d *data)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	while (++y < data->height)
=========
void	draw_map(t_cub3d *data)
{
	int	y;
	int	x;

	y = 0;
	flag = 0;
	while (y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
<<<<<<<<< Temporary merge branch 1
			if (x < (int)ft_strlen(data->raw_map[y]))
			{
				if (check_character(data->raw_map[y][x], 2))
					color = data->color[0];
				if (data->raw_map[y][x] == '1')
					color = data->color[1];
				if (data->raw_map[y][x] == '0')
					color = data->color[0];
			}
			render_map(data, x * BLOCK_SIZE, y * BLOCK_SIZE, color);
		}
	}
}

void	render_player(t_cub3d *data)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (x == data->player_x && y == data->player_y)
			{
				color = data->color[2];
				creat_player(data, x * BLOCK_SIZE + BLOCK_SIZE / 2, y * BLOCK_SIZE + BLOCK_SIZE / 2, color);
				break ;
			}
=========
			put_map_to_window(x, y, data->raw_map[y][x], data);
			if (flag == 1)
			{
				put_player_on_map(x, y, data);
				flag = 0;
			}
			x++;
		}
		y++;
	}
}

void	image_handler(t_cub3d *data)
{
<<<<<<<<< Temporary merge branch 1
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	render_background(data);
	render_2d_map(data);
	render_player(data);
	mlx_put_image_to_window(data->mlx_ptr, \
	data->mlx_window, data->img->img_ptr, 0, 0);
=========
	draw_map(data);
	draw_player(data);
	mlx_hook(data->mlx_window, 2, 1L << 1, key_handler, data);
	mlx_hook(data->mlx_window, 17, 0, mouse_handler, data);
	mlx_loop(data->mlx);
>>>>>>>>> Temporary merge branch 2
}

void	init_window(t_cub3d *data)
{
	data->color[0] = 0xFFFFFF;
	data->color[1] = 0x0000FF;
	data->color[2] = 0xFF0000;
<<<<<<<<< Temporary merge branch 1
	data->mlx_ptr = mlx_init();
	//protect mlx_ptr
	data->mlx_window = mlx_new_window(data->mlx_ptr, X, \
							Y, "Cub3D");
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, X, Y);
	//protect mlx_window
	//protect img_ptr
=========
	data->player_x *= 2;
	data->player_y *= 2;
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, 1098, \
							800, "Cub3D");
	image_handler(data);
>>>>>>>>> Temporary merge branch 2
}
