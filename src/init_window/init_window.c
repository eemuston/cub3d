/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 13:36:19 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	init_game_config(t_cub3d *data)
{
	data->minimap_scale = 0.40;
	data->minimap_offset_x = 0;
	data->minimap_offset_y = HEIGHT - (int)(data->height * BLOCK_SIZE
			* data->minimap_scale);
}

int	init_window(t_cub3d *data)
{
	data->color[0] = 0xFFFFFF;
	data->color[1] = 0xFFA500;
	data->color[2] = 0xFF0000;
	data->mlx_ptr = mlx_init();
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"/Users/atoof/cub3d/wall1h.xpm", &data->texture[0].width,
			&data->texture[0].height);
	data->texture[0].data = (int *)mlx_get_data_addr(data->texture[0].img,
			&data->texture[0].bpp, &data->texture[0].size_line,
			&data->texture[0].endian);
	data->texture[1].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"texture/wall_brick_black.xpm", &data->texture[1].width,
			&data->texture[1].height);
	data->texture[1].data = (int *)mlx_get_data_addr(data->texture[1].img,
			&data->texture[1].bpp, &data->texture[1].size_line,
			&data->texture[1].endian);
	data->texture[2].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"texture/wall_brick_gray.xpm", &data->texture[2].width,
			&data->texture[2].height);
	data->texture[2].data = (int *)mlx_get_data_addr(data->texture[2].img,
			&data->texture[2].bpp, &data->texture[2].size_line,
			&data->texture[2].endian);
	data->texture[3].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"texture/wall_brick_orange.xpm", &data->texture[3].width,
			&data->texture[3].height);
	data->texture[3].data = (int *)mlx_get_data_addr(data->texture[3].img,
			&data->texture[3].bpp, &data->texture[3].size_line,
			&data->texture[3].endian);
	data->brick_texture.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"/Users/atoof/cub3d/brick.xpm", &data->brick_texture.width,
			&data->brick_texture.height);
	data->brick_texture.data = (int *)mlx_get_data_addr(data->brick_texture.img,
			&data->brick_texture.bpp, &data->brick_texture.size_line,
			&data->brick_texture.endian);
	if (!data->mlx_ptr)
		return (error_in_img(data, 1));
	data->mlx_window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->mlx_window)
		return (error_in_img(data, 2));
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img->img_ptr)
		return (error_in_img(data, 3));
	init_game_config(data);
	return (0);
}
