/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:02:19 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 19:02:19 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, unsigned int size)
{
	unsigned int	i;
	char			*from_cpy;
	char			*to_cpy;

	from_cpy = (char *)from;
	to_cpy = (char *)to;
	i = 0;
	if (!to && !from)
		return ((void *)0);
	while (i < size)
	{
		to_cpy[i] = from_cpy[i];
		i++;
	}
	return (to_cpy);
}
