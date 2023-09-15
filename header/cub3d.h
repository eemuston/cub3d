/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:27:23 by atoof             #+#    #+#             */
/*   Updated: 2023/09/15 16:13:54 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>

/* keys */
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2

/* Directions */
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

/* Sizes */
# define BLOCK_SIZE 24
# define PLAYER_SIZE 24

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
	void			*mlx;
	void			*mlx_window;
	int				color[3];
	int				width;
	int				height;
	int				fd;
	int				player;
	int				player_x;
	int				player_y;
	int				tmp_player_x;
	int				tmp_player_y;
	char			player_direction;
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
void				free_map(t_map **map);
// read_file.c:
int					read_file_and_parse(char **argv, t_cub3d *data);
int					error_in_texture(t_cub3d *data, int flag);
int					error_check(int argc, char **argv);

// textture_color_init.c:
int					texture_color_init(char **splitted_line, t_cub3d *data);

// get_raw_map.c:
int					get_raw_map(t_cub3d *data, int fd);
int					add_new_node_to_map(char *line, t_cub3d *data);

// flood_fill_algorithm
int					flood_fill(char **raw_map, t_cub3d *data);
int					allocate_temp_map(char ***temp_map, char **raw_map,
						int height, int width);

// check_map_path_color.c:
int					check_valid_color(t_cub3d *data);
int					check_texture_path(t_cub3d *data, int current);

// check_validity:
int					not_valid_line(char *current);
int					valid_map(t_cub3d *data, char **raw_map);
int					check_amount_player(char **map, int index, t_cub3d *d);

// utils:
long long			ft_atoll(const char *str);
int					mouse_handler(t_cub3d *data);
int					check_character(char c, int flag);
int					check_valid_line(char **map, int flag);
void	assign_player_map_dimension(t_cub3d *data,
									char **map,
									int *temp);
int					check_map_zeros(t_cub3d *data);
int					key_handler(int key, t_cub3d *data);

// init_window:
void				put_to_win(t_cub3d *data);
void				init_window(t_cub3d *data);
void				image_handler(t_cub3d *data);

#endif