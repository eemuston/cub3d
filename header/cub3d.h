/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:27:23 by atoof             #+#    #+#             */
/*   Updated: 2023/10/03 18:54:17 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

/* arrow keys */
# define LEFT 123
# define RIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4
# define TRUE 1
# define FALSE 0
# define WIDTH 1920
# define HEIGHT 1080

# define BLOCK_SIZE 30
# define PLAYER_SIZE 5
# define SPEED 0.8
# define ANGLE 5.0
# define FOV 60

typedef struct s_ray
{
	double			x;
	double			y;
	double			angle;
	double			dist;
	double			dir_x;
	double			dir_y;
	double			p_delta_x;
	double			p_delta_y;
	int				steps_x;
	int				steps_y;
	double			center_angle;
	double			half_fov;
	double			start_angle;
	double			end_angle;
	double			angle_increment;
}					t_ray;

typedef struct s_texture
{
	char			*path;
	int				identifier;
}					t_texture;

typedef struct s_point
{
	double			p_x;
	double			p_y;
}					t_point;

typedef struct s_line
{
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			step;
}					t_line;

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
}					t_img;

typedef struct s_player
{
	double			player_x;
	double			player_y;
	double			pixel_x;
	double			pixel_y;
	double			pdx;
	double			pdy;
	double			tmp_player_x;
	double			tmp_player_y;
	double			player_angle;
}					t_player;

/* cub3D struct */
typedef struct s_cub3d
{
	bool			keys[125];
	int				color[3];
	int				found_zero;
	int				found_space;
	int				width;
	int				height;
	int				fd;
	double			minimap_scale;
	int				minimap_offset_x;
	int				minimap_offset_y;
	int				player_number;
	char			player_direction;
	void			*mlx_ptr;
	void			*mlx_window;
	char			**raw_map;
	char			**valid_map;
	t_player		*player;
	t_map			*map;
	t_img			*img;
	t_texture		texture[4];
	t_color			colors[2];
	t_ray			*ray;
}					t_cub3d;

// init.c:
int					init_data(t_cub3d *data);

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
int					flood_fill_inside_map(char **raw_map, t_cub3d *data);
int					flood_fill_outside_map(char **temp_map, t_cub3d *data);
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
double				degree_to_rad(double angle);
long long			ft_atoll(const char *str);
char				**ft_split_spaces(char *str);
void				set_player_x_y(t_cub3d *data);
int					mouse_handler(t_cub3d *data);
int					check_character(char c, int flag);
int					check_valid_line(char **map, int flag);
void				assign_player_map_dimension(t_cub3d *data, \
					char **map);

// init_window:
void				draw_2d_map(t_cub3d *data);
void				draw_2d_player(t_cub3d *data);
void				draw_2d_direction(t_cub3d *data);
void				draw_rayline(t_cub3d *data);
int					init_window(t_cub3d *data);
void				draw_fov(t_cub3d *data);
void				render_game(t_cub3d *data);
void				render_background(t_cub3d *data);
int					error_in_img(t_cub3d *data, int flag);
void				dda_algorithm(t_point p1, t_point p2, t_cub3d *data, \
					t_line line);

//image_handler
void				my_mlx_pixel_put(t_cub3d *data, double x, double y, \
					unsigned int color);
void				my_mlx_pixel_put_mini(t_cub3d *data, double width, \
					double height, unsigned int color);

//key_events
void				hook_keys_loop(t_cub3d *data);
void				move_keys(t_cub3d *data);
void				arrow_keys(t_cub3d *data);
void				update_player_coordinates(t_cub3d *data);
int					key_release_handler(int key, t_cub3d *data);

// ray

void				grid_to_pixel(t_cub3d *data);
bool				is_in_map(t_cub3d *data, double x, double y);
bool				is_not_wall(t_cub3d *data, double x, double y);
void				update_position(double *x, double *y, double angle, \
					double distance);

#endif