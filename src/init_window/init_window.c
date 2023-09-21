/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/09/21 13:19:20 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	init_window(t_cub3d *data)
{
	data->color[0] = 0xFFFFFF;
	data->color[1] = 0xFFA500;
	data->color[2] = 0xFF0000;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error_in_img(data, 1);
	data->mlx_window = mlx_new_window(data->mlx_ptr, X, \
							Y, "Cub3D");
	if (!data->mlx_window)
		error_in_img(data, 2);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, X, Y);
	if (!data->img->img_ptr)
		error_in_img(data, 3);
}
