/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:07:50 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/08 14:46:20 by vvu              ###   ########.fr       */
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
		printf("path = %s\n", data->texture[i].path);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		printf("%c ", data->colors[i].name);
		printf("%s\n", data->colors[i].color);
		i++;
	}
	i = 0;
	printf("raw map: \n");
	while (data->raw_map[i])
	{
		printf("%s\n", data->raw_map[i]);
		i++;
	}
}

void	display_map(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	while (tmp != NULL)
	{
		if (tmp->line)
			printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_cub3d	data;

	init_data(&data);
	if (error_check(argc, argv, &data) == 1)
		return (1);
	print_struct(&data);
	//display_map(&data.map);
	//parse_map();
	free_texture(&data);
	return (0);
}
