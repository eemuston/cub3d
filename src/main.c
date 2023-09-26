/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:07:50 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/26 14:54:36 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	set_player_x_y(t_cub3d *data)
{
	data->player->player_x = (data->player->player_x * BLOCK_SIZE / PLAYER_SIZE)
		+ (BLOCK_SIZE / PLAYER_SIZE / 2);
	data->player->player_y = (data->player->player_y * BLOCK_SIZE / PLAYER_SIZE)
		+ (BLOCK_SIZE / PLAYER_SIZE / 2);
}

int	main(int argc, char **argv)
{
	t_cub3d	data;

	if (init_data(&data))
		return (1);
	if (error_check(argc, argv) == 1)
		return (1);
	if (read_file_and_parse(argv, &data) == 1)
		return (1);
	if (init_window(&data))
		return (1);
	set_player_x_y(&data);
	render_game(&data);
	hook_keys_loop(&data);
	free_texture(&data);
	return (0);
}
