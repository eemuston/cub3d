/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:27:23 by atoof             #+#    #+#             */
/*   Updated: 2023/09/08 13:34:49 by vvu              ###   ########.fr       */
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
	int				identifier;
}					t_texture;

typedef struct s_color
{
	char			name;
	char			*color;
	short			rgb[3];
}					t_color;

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

/* cub3D struct */
typedef struct s_cub3d
{
	int				width;
	int				height;
	int				fd;
	char			**raw_map;
	t_map			*map;
	t_texture		texture[4];
	t_color			colors[2];
}					t_cub3d;

// init.c:
void				init_data(t_cub3d *data);

// free.c:
void				free_array(char **array);
void				free_texture(t_cub3d *data);

// read_file.c:
int					read_file(char **argv, t_cub3d *data);
int					error_in_texture(t_cub3d *data, int flag);
int					error_check(int argc, char **argv, t_cub3d *data);

// textture_color_init.c:
int					texture_color_init(char **splitted_line, t_cub3d *data);

// get_raw_map.c:
int					get_raw_map(t_cub3d *data, int fd);
int					check_map(t_cub3d *data, int current);

#endif