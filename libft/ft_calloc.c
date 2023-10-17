/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:02:10 by atoof             #+#    #+#             */
/*   Updated: 2023/10/12 15:02:10 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	mult;

	mult = count * size;
	if (count > 0 && size > 0)
	{
		if (mult % count != 0 || mult % size != 0)
			return (NULL);
	}
	pointer = malloc(mult);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, mult);
	return (pointer);
}
