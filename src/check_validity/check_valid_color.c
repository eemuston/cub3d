/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:31:14 by vvu               #+#    #+#             */
/*   Updated: 2023/09/17 16:45:42 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	assign_color_to_data(t_cub3d *data, int array, char **color)
{
	int	index;

	index = -1;
	while (++index < 3)
		data->colors[array].rgb[index] = ft_atoi(color[index]);
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
		while (color_check[index][current] != '\0')
		{
			if (color_check[index][current] != '\n' && \
			!ft_isdigit(color_check[index][current]))
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
	int		array;

	array = -1;
	while (++array < 2)
	{
		index = 0;
		color_check = ft_split(data->colors[array].color, ',');
		if (!color_check)
			return (error_in_texture(data, 4));
		while (color_check[index] != NULL)
			index++;
		if (index != 3 || is_not_number(color_check))
		{
			free_array(color_check);
			return (error_in_texture(data, 6));
		}
		assign_color_to_data(data, array, color_check);
		free_array(color_check);
	}
	return (0);
}
