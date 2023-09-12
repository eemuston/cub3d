/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:52:45 by vvu               #+#    #+#             */
/*   Updated: 2023/09/12 17:41:51 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	assign_map_to_cub3d(t_cub3d *data, int lst_size, \
								int index, t_map *current)
{
	current = data->map;
	while (current != NULL)
	{
		lst_size++;
		current = current->next;
	}
	data->raw_map = ft_calloc(sizeof(char *), lst_size + 1);
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
	return (0);
}

int	free_line(char *line, t_cub3d *data)
{
	free(line);
	return (error_in_texture(data, 5));
}

int	get_raw_map(t_cub3d *data, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line && line[0] == '\n' && data->map == NULL)
		{
			free(line);
			continue ;
		}
		else if ((line && line[0] == '\n' && data->map != NULL) \
		|| not_valid_line(line))
			return (free_line(line, data));
		if (add_new_node_to_map(line, data))
			return (1);
		free(line);
	}
	if (assign_map_to_cub3d(data, 0, -1, NULL))
		return (error_in_texture(data, 5));
	free_map(&data->map);
	data->map = NULL;
	close(fd);
	return (0);
}
