/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:03:22 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 19:03:22 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_lng;
	size_t	src_lng;
	size_t	i;

	src_lng = ft_strlen(src);
	dest_lng = 0;
	if (dst)
		dest_lng = ft_strlen(dst);
	i = dest_lng;
	if (!src || !*src)
		return (dest_lng);
	else if (dstsize <= dest_lng)
		return (dstsize + src_lng);
	while (*src && dstsize > dest_lng && i != dstsize - 1)
		*(dst + i++) = *src++;
	*(dst + i) = '\0';
	return (dest_lng + src_lng);
}
