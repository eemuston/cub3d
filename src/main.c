/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:07:50 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/11 17:17:16 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

// static void	print_struct(t_cub3d *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("identifier = %d : ", data->texture[i].identifier);
// 		printf("path = %s\n", data->texture[i].path);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 2)
// 	{
// 		printf("%c ", data->colors[i].name);
// 		printf("%d %d %d\n", data->colors[i].rgb[0], \
// 		data->colors[i].rgb[1], data->colors[i].rgb[2]);
// 		i++;
// 	}
// 	i = 0;
// 	printf("raw map: \n");
// 	while (data->raw_map[i])
// 	{
// 		printf("%s\n", data->raw_map[i]);
// 		i++;
// 	}
// }

int	main(int argc, char **argv)
{
	t_cub3d	data;

	init_data(&data);
	if (error_check(argc, argv, &data) == 1)
		return (1);
	//print_struct(&data);
	//parse_map();
	free_texture(&data);
	return (0);
}
