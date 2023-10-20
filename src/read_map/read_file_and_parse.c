/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_and_parse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:24:30 by atoof             #+#    #+#             */
/*   Updated: 2023/10/20 17:40:55 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	check_valid_input(char **splitted_line, t_cub3d *data)
{
	int	i;

	i = 0;
	while (splitted_line[i])
		i++;
	if (i == 2 && ((!ft_strncmp(splitted_line[0], "NO", 2)
				|| !ft_strncmp(splitted_line[0], "EA", 2)
				|| !ft_strncmp(splitted_line[0], "WE", 2)
				|| !ft_strncmp(splitted_line[0], "SO", 2)) && \
		(ft_strncmp(splitted_line[1] + \
			ft_strlen(splitted_line[1]) - 5, ".xpm\n", 5)) != 0))
	{
		ft_putstr_fd("Error\nNot a xpm file\n", 2);
		free_texture(data);
		return (1);
	}
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

int	read_file_and_parse(t_cub3d *data)
{
	if (read_texture_color(data->fd, data) || \
		check_texture_path(data, 0) || check_valid_color(data) || \
		get_raw_map(data, data->fd) || \
		check_amount_player(data->raw_map, 0, data) || \
		valid_map(data))
		return (1);
	return (0);
}
