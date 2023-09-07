/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:29:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/07 18:38:02 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	check_valid_input(char **splitted_line, t_cub3d *data)
{
	int	i;

	i = 0;
	while (splitted_line[i] && ft_strncmp(splitted_line[i], "\n", 1))
		i++;
	if (i > 2)
		return (error_in_texture(data, 3));
	return (0);
}

static int	split_line(char *line, t_cub3d *data)
{
	char	**splitted_line;

	splitted_line = ft_split(line, ' ');
	if (check_valid_input(splitted_line, data)
		|| texture_color_init(splitted_line, data))
	{
		free_array(splitted_line);
		free(line);
		return (1);
	}
	free_array(splitted_line);
	return (0);
}

static int	read_texture_color(int fd, t_cub3d *data)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_texture(data);
			break ;
		}
		if ((line[0] != '\0') && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (split_line(line, data))
			return (1);
		free(line);
		i++;
	}
	if (i <= 5)
		return (error_in_texture(data, 3));
	return (0);
}

static int	check_duplicate(t_cub3d *data)
{
	int	index;
	int	cur_index;
	int	temp;

	index = 0;
	while (index < 3)
	{
		cur_index = index;
		while (cur_index < 3)
		{
			temp = data->texture[cur_index + 1].identifier;
			if (data->texture[index].identifier == temp)
				return (error_in_texture(data, 2));
			cur_index++;
		}
		index++;
	}
	return (0);
}

int	read_file(char **argv, t_cub3d *data)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error could not open file.\n", 2);
		return (1);
	}
	if (read_texture_color(fd, data))
	{
		close(fd);
		return (1);
	}
	close(fd);
	// TODO: check if we have correct info in colors and texture structures;
	if (check_duplicate(data))
		return (1);
	return (0);
}
