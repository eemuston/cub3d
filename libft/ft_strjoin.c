/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:03:18 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 19:03:18 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*sjoin;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	sjoin = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!sjoin)
		return (NULL);
	i = -1;
	while (s1[++i])
		sjoin[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		sjoin[len1] = s2[i];
		len1++;
	}
	sjoin [len1] = '\0';
	return (sjoin);
}
