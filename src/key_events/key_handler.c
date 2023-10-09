/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:42 by vvu               #+#    #+#             */
/*   Updated: 2023/10/07 16:17:14 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	mouse_handler(t_cub3d *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	free_texture(data);
	exit(0);
}

int	key_press_handler(int key, t_cub3d *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		free_texture(data);
		exit(0);
	}
	if (key == W || key == S || key == D || key == A || \
	key == LEFT || key == RIGHT)
		data->keys[key] = TRUE;
	return (0);
}

int	key_release_handler(int key, t_cub3d *data)
{
	if (key == W || key == S || key == D || key == A || \
		key == LEFT || key == RIGHT)
		data->keys[key] = FALSE;
	return (0);
}

int	keys(t_cub3d *data)
{
	data->player->tmp_player_x = data->player->player_x * BLOCK_SIZE;
	data->player->tmp_player_y = data->player->player_y * BLOCK_SIZE;
	if (data->keys[W] || data->keys[S] || data->keys[A] || data->keys[D])
		move_keys(data);
	if (data->keys[RIGHT] || data->keys[LEFT])
		arrow_keys(data);
	update_player_coordinates(data);
	return (0);
}

void	hook_keys_loop(t_cub3d *data)
{
	mlx_hook(data->mlx_window, 2, 1L << 0, key_press_handler, data);
	mlx_hook(data->mlx_window, 3, 1L << 1, key_release_handler, data);
	mlx_loop_hook(data->mlx_ptr, keys, data);
	mlx_hook(data->mlx_window, 17, 0, mouse_handler, data);
	mlx_loop(data->mlx_ptr);
}
