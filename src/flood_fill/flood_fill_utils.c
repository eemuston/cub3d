/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:39:03 by vvu               #+#    #+#             */
/*   Updated: 2023/09/20 12:29:20 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	allocate_temp_map(char ***temp_map, char **raw_map, int height, int width)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	*temp_map = ft_calloc(sizeof(char *), height + 2);
	if (!(*temp_map))
		return (1);
	while (raw_map[y] != NULL)
	{
		(*temp_map)[y] = ft_calloc(sizeof(char), width + 2);
		if (!((*temp_map)[y]))
			return (1);
		y++;
	}
	(*temp_map)[y] = NULL;
	while (i < height)
	{
		ft_memmove((*temp_map)[i], raw_map[i], ft_strlen(raw_map[i]));
		i++;
	}
	return (0);
}

int	check_valid_line(char **map, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (check_character(map[i][j], flag))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
