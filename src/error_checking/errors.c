/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:04:51 by vvu               #+#    #+#             */
/*   Updated: 2023/10/09 19:04:53 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	error_in_texture(t_cub3d *data, int flag)
{
	if (flag == 1)
		ft_putstr_fd("Error\nInvalid texture identifier.\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Error\nDuplicate texture direction\n", 2);
	else if (flag == 3)
		ft_putstr_fd("Error\nInvalide input\n", 2);
	else if (flag == 4)
		ft_putstr_fd("Error\nMalloc\n", 2);
	else if (flag == 5)
		ft_putstr_fd("Error\nInvalid input around the map\n", 2);
	else if (flag == 6)
		ft_putstr_fd("Error\nInvalid colors\n", 2);
	else if (flag == 7)
		ft_putstr_fd("Error\nInvalid player number\n", 2);
	else if (flag == 8)
		ft_putstr_fd("Error\nInvalid texture path\n", 2);
	else if (flag == 9)
		ft_putstr_fd("Error\nMap not surrounded by 1\n", 2);
	else if (flag == 10)
		ft_putstr_fd("Error\nFound space inside map\n", 2);
	else if (flag == 11)
		ft_putstr_fd("Error\nFound island\n", 2);
	free_texture(data);
	return (1);
}

int	error_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Not right amount of arguments.\n", 2);
		ft_putstr_fd("Usage ./cub3D [mapfile].cub\n", 2);
		return (1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Not a .cub file.\n", 2);
		ft_putstr_fd("Usage ./cub3D [mapfile].cub\n", 2);
		return (1);
	}
	return (0);
}

static void	destroy_image_ptr(t_cub3d *data)
{
	if (data->img->img_ptr && data->mlx_window && data->mlx_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	}
	else if (data->mlx_window && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	else if (data->img->img_ptr && data->mlx_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	free_texture(data);
}

int	error_in_img(t_cub3d *data, int flag)
{
	if (flag == 1)
		printf("Error\nCouldn't initialize mlx_ptr\n");
	else if (flag == 2)
		printf("Error\nCouldn't create window\n");
	else if (flag == 3)
		printf("Error\nCouldn't create the image\n");
	destroy_image_ptr(data);
	return (1);
}
