/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:07:50 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/06 19:32:31 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	print_struct(t_cub3d *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		printf("identifier = %d : ", data->texture[i].identifier);
		printf("key = %s ", data->texture[i].key);
		printf("path = %s", data->texture[i].path);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_cub3d	data;

	init_data(&data);
	if (error_check(argc, argv, &data) == 1)
		return (1);
	print_struct(&data);
	//parse_map();
	free_texture(&data);

	return (0);
}
