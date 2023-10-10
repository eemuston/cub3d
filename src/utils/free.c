/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/10/10 14:16:52 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/cub3d.h"

void	free_map(t_map **map)
{
	t_map	*tmp;

	if (!(*map))
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
	(*map) = NULL;
}

void	free_texture(t_cub3d *data)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		if (data->colors[i].color)
			free(data->colors[i].color);
		data->colors[i].color = NULL;
	}
	i = -1;
	while (++i < 4)
	{
		if (data->texture[i].path != NULL)
			free(data->texture[i].path);
		data->texture[i].path = NULL;
	}
	if (data->map != NULL)
		free_map(&data->map);
	if (data->raw_map != NULL)
		free_array(data->raw_map);
	free(data->img);
	free(data->player);
	close(data->fd);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!(*array))
		return ;
	else
	{
		while (array[i] != NULL)
		{
			if (array[i] != NULL)
				free(array[i]);
			array[i] = NULL;
			i++;
		}
	}
	free(array);
	array = NULL;
}

void	destroy_image(t_cub3d *data)
{
	int	i;

	i = -1;
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	while (++i < 4)
		mlx_destroy_image(data->mlx_ptr, data->texture[i].img);
}
