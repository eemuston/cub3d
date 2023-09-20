/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:07:50 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/20 13:37:15 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

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
	// printf("pa: %f\n",data.pa);
	// printf("cos: %f\n",cos(data.pa));
	// printf("sin: %f\n",sin(data.pa));
	// printf("tan: %f\n",tan(data.pa));
	// data.pdz = cos(data.pa) / data.pdx;
	// printf("pz %f\n", data.pdz);
	init_window(&data);
	render_game(&data);
	hook_keys_loop(&data);
	free_texture(&data);
	return (0);
}
