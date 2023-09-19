/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:49:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/17 16:49:40 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	check_splitptr_len(char **splitted_line)
{
	int	len;

	len = 0;
	if (!splitted_line)
		return (0);
	while (splitted_line[len] != NULL)
		len++;
	return (len);
}

char	*join_splitted_line(char **splitted_line)
{
	int		index;
	char	*result;
	char	*tmp;

	index = 1;
	result = ft_calloc(1, 1);
	while (splitted_line[index])
	{
		tmp = ft_strjoin(result, splitted_line[index]);
		if (!tmp)
		{
			if (result != NULL)
				free(result);
			return (NULL);
		}
		if (result != NULL)
			free(result);
		result = tmp;
		index++;
	}
	return (result);
}
