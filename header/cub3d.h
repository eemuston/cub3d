/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:27:23 by atoof             #+#    #+#             */
/*   Updated: 2023/09/19 11:44:52 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>

/* arrow keys */
# define LEFT 123
# define RIGHT 124

# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

# define X 1920
# define Y 1080

# define BLOCK_SIZE 16
# define PLAYER_SIZE 4

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

/* cub3D image struct */
typedef struct s_img
{
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_img;

/* cub3D struct */
typedef struct s_cub3d
{
	int				color[3];
	int				found_zero;
	int				width;
	int				height;
	int				fd;
	int				player;
	double			player_x;
	double			player_y;
	double			tmp_player_x;
	double			tmp_player_y;
	double			pdx;
	double			pdy;
	double			pa;
	char			player_direction;
	void			*mlx_ptr;
	void			*mlx_window;
	char			**raw_map;
	char			**valid_map;
	t_map			*map;
	t_img			*img;
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
int					check_splitptr_len(char **splitted_line);
char				*join_splitted_line(char **splitted_line);
int					texture_color_init(char **splitted_line, t_cub3d *data);

// get_raw_map.c:
int					get_raw_map(t_cub3d *data, int fd);
int					add_new_node_to_map(char *line, t_cub3d *data);

// flood_fill_algorithm
int					flood_fill(char **raw_map, t_cub3d *data);
int					allocate_temp_map(char ***temp_map, char **raw_map, \
					int height, int width);

// check_map_path_color.c:
int					check_valid_color(t_cub3d *data);
int					check_texture_path(t_cub3d *data, int current);

// check_validity:
int					not_valid_line(char *current);
int					valid_map(t_cub3d *data);
int					check_amount_player(char **map, int index, t_cub3d *d);

// utils:
long long			ft_atoll(const char *str);
int					mouse_handler(t_cub3d *data);
int					check_character(char c, int flag);
int					check_valid_line(char **map, int flag);
void				assign_player_map_dimension(t_cub3d *data, \
									char **map, int *temp);
int					key_handler(int key, t_cub3d *data);

// init_window:
void				draw_map(t_cub3d *data);
void				draw_player(t_cub3d *data);
void				init_window(t_cub3d *data);
void				image_handler(t_cub3d *data);
void				render_background(t_cub3d *data);

//image_handler
void				my_mlx_pixel_put(t_cub3d *data, int x, int y, \
					unsigned int color);

#endif