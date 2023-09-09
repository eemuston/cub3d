/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:36:29 by vvu               #+#    #+#             */
/*   Updated: 2023/09/09 13:12:25 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	is_1_and_space(int c)
{
	return ((c == '1' || c == 32 || c == '\t') && c != '\0');
}

static int	first_chr_is_1(char **raw_map, int line, \
							int index, int last_line)
{
	while (++line <= last_line)
		if (raw_map[line][index] != '1')
			return (1);
	return (0);
}

static int	last_chr_is_1(char **raw_map, int line, \
							size_t index, int last_line)
{
	while (++line <= last_line)
	{
		index = ft_strlen(raw_map[line]);
		if (raw_map[line][--index] != '1')
			return (1);
	}
	return (0);
}

int	check_surround_by_1(t_cub3d *data, char **raw_map, \
						int first_line, int last_line)
{
	size_t	index_first;
	size_t	index_last;
	size_t	len_fisrt_line;
	size_t	len_last_line;

	index_first = 0;
	index_last = 0;
	while (raw_map[last_line] != NULL)
		last_line++;
	len_fisrt_line = ft_strlen(raw_map[first_line]);
	len_last_line = ft_strlen(raw_map[--last_line]);
	while (is_1_and_space(raw_map[first_line][index_first]))
		index_first++;
	while (is_1_and_space(raw_map[last_line][index_last]))
		index_last++;
	if ((index_first != len_fisrt_line) || index_last != len_last_line)
		return (error_in_texture(data, 7));
	if (first_chr_is_1(raw_map, -1, 0, last_line) || \
		last_chr_is_1(raw_map, -1, 0, last_line))
		return (error_in_texture(data, 7));
	return (0);
}
