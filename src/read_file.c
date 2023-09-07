/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:29:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/06 19:23:52 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	allocate_texture(t_cub3d *data, char **splitted_line, int flag,
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
	data->texture[i].key = ft_strdup(splitted_line[0]);
	data->texture[i].path = ft_strdup(splitted_line[1]);
	if (!data->texture[i].path || !data->texture[i].key)
		return(error_in_texture(data, 4));
	return (0);
}

static int	texture_init(char **splitted_line, t_cub3d *data, int i)
{
	if (!ft_memcmp(splitted_line[0], "NO", ft_strlen(splitted_line[0])))
	{
		if (allocate_texture(data, splitted_line, 1, i))
			return (1);
	}
	else if (!ft_memcmp(splitted_line[0], "SO", ft_strlen(splitted_line[0])))
	{
		if (allocate_texture(data, splitted_line, 2, i))
			return (1);
	}
	else if (!ft_memcmp(splitted_line[0], "WE", ft_strlen(splitted_line[0])))
	{
		if (allocate_texture(data, splitted_line, 3, i))
			return (1);
	}
	else if (!ft_memcmp(splitted_line[0], "EA", ft_strlen(splitted_line[0])))
	{
		if (allocate_texture(data, splitted_line, 4, i))
			return (1);
	}
	else
		return (error_in_texture(data, 1));
	return (0);
}

static int	check_line_input(char **splitted_line, t_cub3d *data)
{
	int	i;

	i = 0;
	while (splitted_line[i])
		i++;
	if (i > 2)
		return (error_in_texture(data, 3));
	return (0);
}
 //the if line(!) 
 //	return (0);
 //should it be 1, because it is a false ?
static int	read_texture(int fd, t_cub3d *data)
{
	char	*line;
	char	**splitted_line;
	int		i;

	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_texture(data);
			return (1);
		}
		if ((line[0] != '\0') && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		splitted_line = ft_split(line, ' ');
		if (check_line_input(splitted_line, data) || texture_init(splitted_line, data, i))
		{
			free_array(splitted_line);
			free(line);
			return (1);
		}
		free_array(splitted_line);
		free(line);
		i++;
	}
	return (0);
}

static	int	check_duplicate(t_cub3d *data, int current, int next)
{
	char	*check;

	check = NULL;
	while (current < 3)
	{
		next = current;
		while (next < 3)
		{
			check = ft_strdup(data->texture[next + 1].key);
			if (!ft_strncmp(check, data->texture[current].key, 2))
			{
				free(check);
				return (error_in_texture(data, 2));
			}
			free(check);
			check = NULL;
			next++;
		}
		current++;
	}
	return (0);
}

int	read_file(char **argv, t_cub3d *data)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error could not open file.\n", 2);
		return (1);
	}
	if (read_texture(fd, data))
	{
		close(fd);
		return (1);
	}
	close(fd);
	if (check_duplicate(data, 0, 0))
		return (1);
	return (0);
}
