/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:07:50 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/18 19:32:59 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	init_valid_map(t_cub3d *data)
{
	int	index;

	index = -1;
	data->valid_map = ft_calloc(data->height, sizeof(char *));
	if (!data->valid_map)
		return (error_in_texture(data, 4));
	while (++index < data->height)
	{
		data->valid_map[index] = ft_calloc(data->width, sizeof(char));
		if (!data->valid_map[index])
			return (error_in_texture(data, 4));
	}
	index = -1;
	while (++index < data->height)
		ft_memcpy(data->valid_map[index], data->raw_map[index], \
					ft_strlen(data->raw_map[index]));
	data->valid_map[index] = NULL;
	return (0);
}

void	hook_keys_loop(t_cub3d *data)
{
	mlx_hook(data->mlx_window, 2, 1L << 1, key_handler, data);
	mlx_hook(data->mlx_window, 17, 0, mouse_handler, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_cub3d	data;

	init_data(&data);
	if (error_check(argc, argv) == 1)
		return (1);
	if (read_file_and_parse(argv, &data) == 1)
		return (1);
	if (init_valid_map(&data))
		return (1);
	init_window(&data);
	image_handler(&data);
	hook_keys_loop(&data);
	free_texture(&data);
	return (0);
}
