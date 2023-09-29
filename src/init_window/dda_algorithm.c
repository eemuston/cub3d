/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:06:32 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/29 12:34:29 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	dda_algorithm(t_point p1, t_point p2, t_cub3d *data, t_line line)
{
	int	i;

	line.dx = (int)p2.p_x - (int)p1.p_x;
	line.dy = (int)p2.p_y - (int)p1.p_y;
	if (fabs(line.dx) >= fabs(line.dy))
		line.step = fabs(line.dx);
	else
		line.step = fabs(line.dy);
	line.dx = line.dx / line.step;
	line.dy = line.dy / line.step;
	line.x = p1.p_x;
	line.y = p1.p_y;
	i = 0;
	while (i <= line.step)
	{
		my_mlx_pixel_put(data, line.x, line.y, 0x0000FF);
		line.x = line.x + line.dx;
		line.y = line.y + line.dy;
		i++;
	}
}
