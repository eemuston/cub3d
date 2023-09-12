/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:26:50 by vvu               #+#    #+#             */
/*   Updated: 2023/09/08 15:26:50 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

long long	ft_atoll(const char *str)
{
	long long		result;
	int				sign;
	unsigned int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
		if (((unsigned long long)result > ((unsigned long long)LLONG_MAX) && \
			(sign == 1)) || ((sign == -1) && ((unsigned long long)result > \
			(unsigned long long)LLONG_MIN)))
			return (-1);
	}
	return ((long long)sign * result);
}
