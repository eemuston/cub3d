/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:32:47 by eemuston          #+#    #+#             */
/*   Updated: 2023/10/17 16:38:40 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	test_open_file(t_cub3d *data, char **argv)
{
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
	{
		ft_putstr_fd("Error\nCould not open file.\n", 2);
		return (1);
	}
	return (0);
}
