/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:07:50 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/06 16:38:38 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	print_struct(t_cub3d *data)
{
	int	i = 0;
	
	while (i < 4)
	{
		printf("%s ", data->texture[i].path);
		printf("%d \n", data->texture[i].identifier);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_cub3d data;
	
	init_data(&data);
	if (error_check(argc, argv, &data) == 1)
		return (1);
	//parse_map();
	print_struct(&data);
	return (0);
}
