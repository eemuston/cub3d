/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:52:45 by vvu               #+#    #+#             */
/*   Updated: 2023/09/08 13:30:32 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_map(t_cub3d *data, int current)
{
	int	fd;

	while (current < 4)
	{
		fd = open(data->texture[current].path, O_RDONLY);
		if (fd == -1)
			return (error_in_texture(data, 5));
		close(fd);
		current++;
	}
	return (0);
}

int	new_node(t_map **new, char *line)
{
	*new = malloc(sizeof(t_map));
	if (!*new) 
	{
		ft_putstr_fd("malloc in new_node\n", 2);
		return (1);
	}
	if (ft_strrchr(line, '\n'))
		(*new)->line = ft_substr(line, 0, ft_strlen(line) - 1);
	else
		(*new)->line = ft_strdup(line);
	if (!(*new)->line)
	{
		ft_putstr_fd("malloc in new_node\n", 2);
		return (1);
	}
	(*new)->next = NULL;
	return (0);
}

int	add_back_map(t_map **map, t_map *new_node)
{
	t_map	*last;

	last = *map;
	if (*map == NULL)
	{
		*map = new_node;
		return (0);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return (0);
}

int	get_raw_map(t_cub3d *data, int fd)
{
	char	*line;
	t_map	*new;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if ((line[0] != '\0') && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		new = NULL;
		new_node(&new, line);
		if (!new)
			return (1);
		add_back_map(&data->map, new);
		free(line);
	}
	return (0);
}
