/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:52 by vvu               #+#    #+#             */
/*   Updated: 2023/10/11 17:35:41 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	init_texture_data(t_cub3d *data)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		data->texture[index].img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->texture[index].path, &data->texture[index].width,
				&data->texture[index].height);
		data->texture[index].data = (int *)mlx_get_data_addr(
				data->texture[index].img, &data->texture[index].bpp, 
				&data->texture[index].size_line, 
				&data->texture[index].endian);
		index++;
	}
}

static int	init_image(t_cub3d *data)
{
	init_texture_data(data);
	if (!data->texture[NORTH - 1].img || !data->texture[NORTH - 1].data || \
	!data->texture[SOUTH - 1].img || !data->texture[SOUTH - 1].data || \
	!data->texture[WEST - 1].img || !data->texture[WEST - 1].data || \
	!data->texture[EAST - 1].img || !data->texture[EAST - 1].data)
	{
		ft_putstr_fd("Error\nAllocate texture image\n", 2);
		destroy_image(data);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		free_texture(data);
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
	data->mini_img->img_ptr = mlx_new_image(data->mlx_ptr, MINI_WIDTH, \
	MINI_HEIGHT);
	if (!data->img->img_ptr)
		return (error_in_img(data, 3));
	if (init_image(data))
		return (1);
	return (0);
}
