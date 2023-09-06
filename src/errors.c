/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:09:42 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/06 16:54:03 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	texture_init(char **splitted_line, t_cub3d *data, int i)
{
	if (ft_strcmp(splitted_line[0], "NO") == 0)
	{
		data->texture[i].path = ft_strdup(splitted_line[1]);
		if (!data->texture[i].path)
			return (1);
		data->texture[i].identifier = NORTH;
	}
	else if (ft_strcmp(splitted_line[0], "SO") == 0)
	{
		data->texture[i].path = ft_strdup(splitted_line[1]);
		if (!data->texture[i].path)
			return (1);
		data->texture[i].identifier = SOUTH;
	}
	else if (ft_strcmp(splitted_line[0], "WE") == 0)
	{
		data->texture[i].path = ft_strdup(splitted_line[1]);
		if (!data->texture[i].path)
			return (1);
		data->texture[i].identifier = WEST;
	}
	else if (ft_strcmp(splitted_line[0], "EA") == 0)
	{
		data->texture[i].path = ft_strdup(splitted_line[1]);
		if (!data->texture[i].path)
			return (1);
		data->texture[i].identifier = EAST;
	}
	else
	{
		free_texture(data);
		ft_putstr_fd("Error, Invalid texture identifier.\n", 2);
		return ;
	}
}

static int read_file(char **argv, t_cub3d *data)
{
	int	fd;
	char *line;
	int i;
	char **splitted_line;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Could not open file.\n", 2);
		return (1);
	}
	while (i < 4)
	{
		line = get_next_line(fd);
		splitted_line = ft_split(line, ' ');
		free(line);
		texture_init(splitted_line, data, i);
		free_array(splitted_line);
		i++;
	}
	close(fd);
	return (0);
}

int	error_check(int argc, char **argv, t_cub3d *data)
{
	if (argc != 2)
	{
		ft_putstr_fd("Not right amount of arguments.\n", 2);
		ft_putstr_fd("Usage ./cub3D [mapfile].cub\n", 2);
		return (1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Not a .cub file.\n", 2);
		ft_putstr_fd("Usage ./cub3D [mapfile].cub\n", 2);
		return (1);
	}
	if (read_file(argv, data) == 1);
		return (1);
	return (0);
}