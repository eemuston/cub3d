/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:22:07 by atoof             #+#    #+#             */
/*   Updated: 2023/10/12 15:22:08 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

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
	set_color_to_floor_ceiling(&data);
	render_game(&data);
	hook_keys_loop(&data);
	free_texture(&data);
	return (0);
}
