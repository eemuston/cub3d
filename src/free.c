/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:39:35 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/08 13:25:54 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	free_map(t_map **map)
{
	t_map	*tmp;

	if (!map)
		return ;
	while (*map != NULL)
	{
		tmp = (*map)->next;
		if ((*map)->line != NULL)
		{
			free((*map)->line);
			(*map)->line = NULL;
		}
		free(*map);
		*map = tmp;
	}
}

void	free_texture(t_cub3d *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		free(data->colors[i].color);
		data->colors[i].color = NULL;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (data->texture[i].path != NULL)
			free(data->texture[i].path);
		data->texture[i].path = NULL;
		i++;
	}
	free_map(&data->map);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
