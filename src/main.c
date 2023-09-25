/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:07:50 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/25 15:39:10 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	hook_keys_loop(t_cub3d *data)
{
	mlx_hook(data->mlx_window, 2, 1L << 1, key_handler, data);
	mlx_hook(data->mlx_window, 17, 0, mouse_handler, data);
	mlx_loop(data->mlx_ptr);
}

void	set_player_x_y(t_cub3d *data)
{
	data->player->player_x = (data->player->player_x * BLOCK_SIZE / \
	PLAYER_SIZE);// + PLAYER_SIZE / 2;
	data->player->player_y = (data->player->player_y * BLOCK_SIZE / \
	PLAYER_SIZE); //+ PLAYER_SIZE / 2;
}

int	main(int argc, char **argv)
{
	t_cub3d	data;

	init_data(&data);
	if (error_check(argc, argv) == 1)
		return (1);
	if (read_file_and_parse(argv, &data) == 1)
		return (1);
	init_window(&data);
	set_player_x_y(&data);
	render_game(&data);
	hook_keys_loop(&data);
	free_texture(&data);
	return (0);
}
