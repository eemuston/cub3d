/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_and_parse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:29:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/20 18:19:37 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	check_valid_input(char **splitted_line, t_cub3d *data)
{
	int	i;

	i = 0;
	while (splitted_line[i])
		i++;
	if (i > 2 && (!ft_strncmp(splitted_line[0], "NO", 2)
			|| !ft_strncmp(splitted_line[0], "EA", 2)
			|| !ft_strncmp(splitted_line[0], "WE", 2)
			|| !ft_strncmp(splitted_line[0], "SO", 2)))
		return (error_in_texture(data, 3));
	return (0);
}

static int	split_line(char *line, t_cub3d *data)
{
	char	**splitted_line;

	splitted_line = ft_split_spaces(line);
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

static int	read_texture_color(int fd, t_cub3d *data)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
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

int	read_file_and_parse(char **argv, t_cub3d *data)
{
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
	{
		ft_putstr_fd("Error\nCould not open file.\n", 2);
		return (1);
	}
	if (read_texture_color(data->fd, data) || check_duplicate(data) || \
		check_texture_path(data, 0) || check_valid_color(data) || \
		get_raw_map(data, data->fd) || \
		check_amount_player(data->raw_map, 0, data) || \
		valid_map(data))
		return (1);
	return (0);
}
