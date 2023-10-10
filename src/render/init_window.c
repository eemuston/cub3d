/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 18:45:43 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	init_game_config(t_cub3d *data)
{
	data->minimap_scale = 0.40;
	data->minimap_offset_x = 0;
	data->minimap_offset_y = HEIGHT - (int)(data->height * BLOCK_SIZE
			* data->minimap_scale);
}

static void	line_so_long_2(t_cub3d *data)
{
	data->texture[WEST - 1].img = mlx_xpm_file_to_image(data->mlx_ptr, 
			data->texture[WEST - 1].path, &data->texture[WEST - 1].width, 
			&data->texture[WEST - 1].height);
	data->texture[WEST - 1].data = (int *)mlx_get_data_addr(
			data->texture[WEST - 1].img, &data->texture[WEST - 1].bpp, 
			&data->texture[WEST - 1].size_line, 
			&data->texture[WEST - 1].endian);
	data->texture[EAST - 1].img = mlx_xpm_file_to_image(data->mlx_ptr, 
			data->texture[EAST - 1].path, &data->texture[EAST - 1].width,
			&data->texture[EAST - 1].height);
	data->texture[EAST - 1].data = (int *)mlx_get_data_addr(
			data->texture[EAST - 1].img, &data->texture[EAST - 1].bpp, 
			&data->texture[EAST - 1].size_line, 
			&data->texture[EAST - 1].endian);
}

static void	line_so_long_1(t_cub3d *data)
{
	data->texture[NORTH - 1].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture[NORTH - 1].path, &data->texture[NORTH - 1].width,
			&data->texture[NORTH - 1].height);
	data->texture[NORTH - 1].data = (int *)mlx_get_data_addr(
			data->texture[NORTH - 1].img, &data->texture[NORTH - 1].bpp, 
			&data->texture[NORTH - 1].size_line, 
			&data->texture[NORTH - 1].endian);
	data->texture[SOUTH - 1].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture[SOUTH - 1].path, &data->texture[SOUTH - 1].width,
			&data->texture[SOUTH - 1].height);
	data->texture[SOUTH - 1].data = (int *)mlx_get_data_addr(
			data->texture[SOUTH - 1].img, &data->texture[SOUTH - 1].bpp,
			&data->texture[SOUTH - 1].size_line, 
			&data->texture[SOUTH - 1].endian);
}

static int	init_image(t_cub3d *data)
{
	line_so_long_1(data);
	line_so_long_2(data);
	if (!data->texture[NORTH - 1].img || !data->texture[NORTH - 1].data || \
	!data->texture[SOUTH - 1].img || !data->texture[SOUTH - 1].data || \
	!data->texture[WEST - 1].img || !data->texture[WEST - 1].data || \
	!data->texture[EAST - 1].img || !data->texture[EAST - 1].data)
	{
		ft_putstr_fd("Error\nAllocate texture image\n", 2);
		return (1);
	}
	return (0);
}

int	init_window(t_cub3d *data)
{
	data->color[0] = 0xFFFFFF;
	data->color[1] = 0xFFA500;
	data->color[2] = 0xFF0000;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (error_in_img(data, 1));
	data->mlx_window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->mlx_window)
		return (error_in_img(data, 2));
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img->img_ptr)
		return (error_in_img(data, 3));
	if (init_image(data))
		return (1);
	init_game_config(data);
	return (0);
}
