/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:31:14 by vvu               #+#    #+#             */
/*   Updated: 2023/09/08 15:31:16 by vvu              ###   ########.fr       */
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

static int	is_not_number(char **color_check)
{
	int			index;
	int			current;
	long long	nbr_check;

	index = 0;
	while (color_check[index])
	{
		current = 0;
		nbr_check = ft_atoll(color_check[index]);
		if (nbr_check > 255 || nbr_check < 0)
			return (1);
		while (color_check[index][current])
		{
			if (!ft_isdigit(color_check[index][current]))
				return (1);
			current++;
		}
		index++;
	}
	return (0);
}

int	check_valid_color(t_cub3d *data)
{
	char	**color_check;
	int		index;

	index = 0;
	color_check = ft_split(data->colors[index].color, ',');
	if (!color_check)
		return (error_in_texture(data, 4));
	while (color_check[index] != NULL)
		index++;
	if (index != 3 || is_not_number(color_check))
	{
		free_array(color_check);
		return (error_in_texture(data, 6));
	}
	return (0);
}
