/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:19:33 by atoof             #+#    #+#             */
/*   Updated: 2023/10/13 14:19:34 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	delimiter(char c)
{
	return (c == 32 || c == 9 || (c >= 11 && c <= 13));
}

int	count_words(char *str)
{
	int	words;

	words = 0;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		while (delimiter(*str) && *str != '\0')
			str++;
		if (!delimiter(*str) && *str != '\0')
			words++;
		while (!delimiter(*str) && *str != '\0')
			str++;
	}
	return (words);
}

char	*each_string(char **str)
{
	int		len;
	int		index;
	char	*new_str;

	len = 0;
	index = 0;
	while (**str != '\0' && delimiter(**str))
		(*str)++;
	while ((*str)[len] != '\0' && !delimiter((*str)[len]))
		len++;
	new_str = malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (NULL);
	new_str[len] = '\0';
	while (index < len)
	{
		new_str[index] = **str;
		(*str)++;
		index++;
	}
	if (**str != '\0')
		(*str)++;
	return (new_str);
}

char	**ft_split_spaces(char *str)
{
	int		words;
	int		index;
	char	**new_str;

	words = count_words(str);
	if (!words)
		return (NULL);
	new_str = malloc(sizeof(char *) * (words + 1));
	if (!new_str)
		return (NULL);
	new_str[words] = NULL;
	index = 0;
	while (index < words)
	{
		new_str[index] = each_string(&str);
		index++;
	}
	return (new_str);
}
