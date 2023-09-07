/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:27:23 by atoof             #+#    #+#             */
/*   Updated: 2023/09/06 18:40:05 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>

/* arrow keys */
# define LEFT 123
# define RIGHT 124

# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

typedef struct s_texture
{
	char			*path;
	char			*key;
	int				identifier;
}				t_texture;

/* cub3D struct */
typedef struct s_cub3d
{
	int				width;
	int				height;
	int				fd;
	t_texture		texture[4];
}				t_cub3d;

//init.c:
void	init_data(t_cub3d *data);

//free.c:
void	free_array(char **array);
void	free_texture(t_cub3d *data);


//read_file.c:
int		error_in_texture(t_cub3d *data, int flag);
int		read_file(char **argv, t_cub3d *data);
int		error_check(int argc, char **argv, t_cub3d *data);

#endif