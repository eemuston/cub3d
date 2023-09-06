/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:29:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/06 18:52:25 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	allocate_texture(t_cub3d *data, char *splitted_line, int flag,
		int i)
{
	if (flag == 1)
		data->texture[i].identifier = NORTH;
	else if (flag == 2)
		data->texture[i].identifier = SOUTH;
	else if (flag == 3)
		data->texture[i].identifier = WEST;
	else if (flag == 4)
		data->texture[i].identifier = EAST;
	data->texture[i].path = ft_strdup(splitted_line);
	if (!data->texture[i].path)
		return (1);
	return (0);
}

static int	texture_init(char **splitted_line, t_cub3d *data, int i)
{
	if (ft_strncmp(splitted_line[0], "NO", 2) == 0)
	{
		if (allocate_texture(data, splitted_line[1], 1, i))
			return (1);
	}
	else if (ft_strncmp(splitted_line[0], "SO", 2) == 0)
	{
		if (allocate_texture(data, splitted_line[1], 2, i))
			return (1);
	}
	else if (ft_strncmp(splitted_line[0], "WE", 2) == 0)
	{
		if (allocate_texture(data, splitted_line[1], 3, i))
			return (1);
	}
	else if (ft_strncmp(splitted_line[0], "EA", 2) == 0)
	{
		if (allocate_texture(data, splitted_line[1], 4, i))
			return (1);
	}
	else
		return (error_in_texture(data->texture));
	return (0);
}

static int	read_texture(int fd, t_cub3d *data)
{
	char	*line;
	char	**splitted_line;
	int		i;

	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd);
		splitted_line = ft_split(line, ' ');
		if (texture_init(splitted_line, data, i))
			return (1);
		free_array(splitted_line);
		free(line);
		i++;
	}
}

int	read_file(char **argv, t_cub3d *data)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Could not open file.\n", 2);
		return (1);
	}
	if (read_texture(fd, data))
		return (1);
	close(fd);
	return (0);
}
