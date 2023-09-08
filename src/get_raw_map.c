/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:52:45 by vvu               #+#    #+#             */
/*   Updated: 2023/09/08 15:43:36 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	new_node(t_map **new, char *line)
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

static int	add_back_map(t_map **map, t_map *new_node)
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

static int	assign_map_to_cub3d(t_cub3d *data)
{
	int		lst_size;
	int		index;
	t_map	*current;

	current = data->map;
	lst_size = 0;
	index = -1;
	while (current)
	{
		lst_size++;
		current = current->next;
	}
	data->raw_map = malloc(sizeof(char *) * lst_size + 1);
	if (!data->raw_map)
		return (error_in_texture(data, 4));
	current = data->map;
	while (++index < lst_size)
	{
		data->raw_map[index] = ft_strdup(current->line);
		if (!data->raw_map[index])
			return (error_in_texture(data, 4));
		current = current->next;
	}
	data->raw_map[index] = NULL;
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
		if (new_node(&new, line))
			return (error_in_texture(data, 4));
		add_back_map(&data->map, new);
		free(line);
	}
	if (assign_map_to_cub3d(data))
		return (1);
	free_map(&data->map);
	close(fd);
	return (0);
}
