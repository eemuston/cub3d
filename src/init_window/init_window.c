/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/10/07 17:25:28 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	init_game_config(t_cub3d *data)
{
	data->minimap_scale = 0.40;
	data->minimap_offset_x = 0;
	data->minimap_offset_y = HEIGHT - (int)(data->height * BLOCK_SIZE \
			* data->minimap_scale);
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
	init_game_config(data);
	return (0);
}
