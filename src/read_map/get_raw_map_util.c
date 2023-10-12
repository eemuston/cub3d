/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:40:43 by vvu               #+#    #+#             */
/*   Updated: 2023/10/12 14:07:56 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	check_texture_path(t_cub3d *data, int current)
{
	int		fd;

	while (current < 4)
	{
		fd = open(data->texture[current].path, O_RDONLY);
		if (fd == -1)
			return (error_in_texture(data, 8));
		close(fd);
		current++;
	}
	return (0);
}

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

int	add_new_node_to_map(char *line, t_cub3d *data)
{
	t_map	*new;

	new = NULL;
	if (new_node(&new, line))
		return (error_in_texture(data, 4));
	add_back_map(&data->map, new);
	return (0);
}
