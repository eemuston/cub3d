/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:01:20 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 19:01:20 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*s;
	int		numlen;

	num = (long)n;
	numlen = num_len(n);
	s = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!s)
		return (NULL);
	s[numlen--] = '\0';
	if (num < 0)
	{
		num = -num;
		s[0] = '-';
	}
	while (num >= 10)
	{
		s[numlen--] = num % 10 + '0';
		num = num / 10;
	}
	s[numlen] = num + '0';
	return (s);
}
