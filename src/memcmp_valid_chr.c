/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp_valid_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:51:06 by vvu               #+#    #+#             */
/*   Updated: 2023/09/12 11:36:31 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_character(char c, int flag)
{
	if (flag == 1)
		return ((c == '1' || c == 32 || (c >= 9 && c <= 13) || c == '0' || \
				c == 'W' || c == 'S' || c == 'E' || c == 'N'));
	else if (flag == 2)
		return (c == 'W' || c == 'S' || c == 'E' || c == 'N');
	else if (flag == 3)
		return (c == 32 || (c >= 9 && c <= 13) || c == 'X' || c == '\0'); 
	else if (flag == 4)
		return (c == '1' || c == '0');
	else if (flag == 5)
		return (c != '1' && c != '0' && c != 'W' && c != 'S' && c != 'E' && \
				c != 'N');
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

int	cub3d_memcmp(const void *s1, const void *s2, size_t n)
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
