/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:23:19 by atoof             #+#    #+#             */
/*   Updated: 2023/10/13 15:15:01 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

int					init_window(t_cub3d *data);
void				draw_2d_map(t_cub3d *data);
void				draw_2d_player(t_cub3d *data);
void				draw_2d_direction(t_cub3d *data);
void				render_background_mini(t_cub3d *data);
void				my_mlx_pixel_put_mini(t_cub3d *data, double width,
						double height, unsigned int color);
void				dda_algorithm(t_point p1, t_point p2, t_cub3d *data, \
					t_line line);
#endif
