/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:09:42 by eemuston          #+#    #+#             */
/*   Updated: 2023/09/06 15:51:04 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	error_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Not right amount of arguments.\n");
		ft_putstr_fd("Usage ./cub3D [mapfile].cub\n");
		return (1);
	}
	return (0);
}