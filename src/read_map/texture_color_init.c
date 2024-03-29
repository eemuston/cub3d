/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:38:05 by vvu               #+#    #+#             */
/*   Updated: 2023/09/18 18:16:12 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	cub3d_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	size_t				len1;
	size_t				len2;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 < len2)
		n = len2;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

static void	assign_pole(int *nbr, char *direction)
{
	if (!ft_strncmp(direction, "NO", 2))
		*nbr = NORTH;
	else if (!ft_strncmp(direction, "SO", 2))
		*nbr = SOUTH;
	else if (!ft_strncmp(direction, "EA", 2))
		*nbr = EAST;
	else if (!ft_strncmp(direction, "WE", 2))
		*nbr = WEST;
}

static int	allocate_texture(t_cub3d *data, char **splitted_line)
{
	int	index;

	index = 0;
	while (data->texture[index].path && index < 4)
		index++;
	data->texture[index].path = ft_substr(splitted_line[1], 0, \
		ft_strlen(splitted_line[1]) - 1);
	if (!data->texture[index].path)
		return (error_in_texture(data, 4));
	assign_pole(&data->texture[index].identifier, splitted_line[0]);
	return (0);
}

static int	color_init(t_cub3d *data, char **splitted_line)
{
	int	index;
	int	len;

	index = 0;
	if (data->colors[index].color != NULL)
		index++;
	if (splitted_line[0][0] == 'F')
		data->colors[index].name = 'F';
	else
		data->colors[index].name = 'C';
	if (data->colors[index].color != NULL)
		return (error_in_texture(data, 2));
	len = check_splitptr_len(splitted_line);
	if (len == 2)
	{
		data->colors[index].color = ft_substr(splitted_line[1], 0, \
		ft_strlen(splitted_line[1]) - 1);
	}
	else
		data->colors[index].color = join_splitted_line(splitted_line);
	if (!data->colors[index].color)
		return (error_in_texture(data, 4));
	return (0);
}

int	texture_color_init(char **splitted_line, t_cub3d *data)
{
	if (!cub3d_memcmp(splitted_line[0], "NO", ft_strlen(splitted_line[0]))
		|| !cub3d_memcmp(splitted_line[0], "SO", ft_strlen(splitted_line[0]))
		|| !cub3d_memcmp(splitted_line[0], "EA", ft_strlen(splitted_line[0]))
		|| !cub3d_memcmp(splitted_line[0], "WE", ft_strlen(splitted_line[0])))
		return (allocate_texture(data, splitted_line));
	else if (!cub3d_memcmp(splitted_line[0], "F", ft_strlen(splitted_line[0]))
		|| !cub3d_memcmp(splitted_line[0], "C", ft_strlen(splitted_line[0])))
		return (color_init(data, splitted_line));
	else
		return (error_in_texture(data, 1));
	return (0);
}
