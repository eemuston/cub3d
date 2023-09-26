/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:06:32 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/25 17:30:37 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	slop(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	else
		return (-1);
}

unsigned int	ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}

void	bresenham(t_point p1, t_point p2, t_cub3d *data, t_line line)
{
	line.dx = ft_abs((int)p2.p_x - (int)p1.p_x);
	line.dy = ft_abs((int)p2.p_y - (int)p1.p_y);
	line.s_x = slop((int)p1.p_x, (int)p2.p_x);
	line.s_y = slop((int)p1.p_y, (int)p2.p_y);
	line.err = (line.dx - line.dy);
	while ((int)p1.p_x != (int)p2.p_x || (int)p1.p_y != (int)p2.p_y)
	{
		my_mlx_pixel_put(data, p1.p_x, p1.p_y, 0x0000FF);
		line.err2 = (2 * line.err);
		if (line.err2 > -line.dy)
		{
			line.err -= (int)line.dy;
			p1.p_x += (int)line.s_x;
		}
		if (line.err2 < line.dx)
		{
			line.err += (int)line.dx;
			p1.p_y += line.s_y;
		}
	}
	my_mlx_pixel_put(data, p1.p_x, p1.p_y, 0x0000FF);
}
