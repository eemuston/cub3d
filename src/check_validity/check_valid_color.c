/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:23:05 by atoof             #+#    #+#             */
/*   Updated: 2023/10/14 15:23:06 by atoof            ###   ########.fr       */
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

	index = -1;
	while (color_check[++index] != NULL)
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
		nbr_check = ft_atoll(color_check[index]);
		if (nbr_check > 255 || nbr_check < 0)
			return (1);
	}
	return (0);
}

static int	check_dup_color(t_cub3d *data)
{
	int	index;

	index = 0;
	if (data->colors[index].name == data->colors[index + 1].name)
	{
		ft_putstr_fd("Error\nDuplicated color names\n", 2);
		free_texture(data);
		return (1);
	}
	return (0);
}

static	int	check_comma(char *comma)
{
	int	n_of_comma;
	int	index;

	index = -1;
	n_of_comma = 0;
	while (comma[++index] != '\0')
	{
		if (comma[index] == ',')
			n_of_comma++;
	}
	if (n_of_comma != 2)
		return (1);
	return (0);
}

int	check_valid_color(t_cub3d *data)
{
	char	**color_check;
	int		array;

	array = -1;
	while (++array < 2)
	{
		if (check_comma(data->colors[array].color))
			return (error_in_texture(data, 6));
		color_check = ft_split(data->colors[array].color, ',');
		if (!color_check)
			return (error_in_texture(data, 4));
		if (is_not_number(color_check))
		{
			free_array(color_check);
			return (error_in_texture(data, 6));
		}
		assign_color_to_data(data, array, color_check);
		free_array(color_check);
	}
	if (check_dup_color(data))
		return (1);
	return (0);
}
