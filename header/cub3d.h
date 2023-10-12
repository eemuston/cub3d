/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:59:59 by vvu               #+#    #+#             */
/*   Updated: 2023/10/12 14:02:32 by vvu              ###   ########.fr       */
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

//Direction
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

# define TRUE 1
# define FALSE 0

//Window size and block_size
# define WIDTH 1000
# define HEIGHT 800
# define MINI_WIDTH 200
# define MINI_HEIGHT 200
# define BLOCK_SIZE 20
# define PLAYER_SIZE 5
# define SPEED 2
# define ANGLE 10
# define FOV 60

typedef struct s_texture
{
	char			*path;
	void			*img;
	int				*data;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
	int				identifier;
}					t_texture;

typedef struct s_point
{
	double			p_x;
	double			p_y;
}					t_point;

typedef struct s_ray
{
	t_point			ray_pos;
	t_point			ray_dir;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			wall_distance;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				wall_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				texture_x;
	int				texture_y;
	int				texture_offset;
	int				color;
}					t_ray;

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
	void			*n_wall;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

/* cub3D player struct */
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
	unsigned int	ceil_color;
	unsigned int	floor_color;
	int				color[3];
	int				found_zero;
	int				found_space;
	int				width;
	int				height;
	int				fd;
	void			*selected_texture;
	int				texture_h;
	int				texture_w;
	int				*texture_data;
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
	t_img			*mini_img;
	t_ray			*ray;
	t_texture		texture[4];
	t_color			colors[2];
}					t_cub3d;

// error_checking:
int					error_check(int argc, char **argv);
void				error_in_init_texture(t_cub3d *data);
int					error_in_img(t_cub3d *data, int flag);
int					error_in_texture(t_cub3d *data, int flag);

// utils:
void				free_array(char **array);
void				free_texture(t_cub3d *data);
void				free_map(t_map **map);
void				destroy_image(t_cub3d *data);
long long			ft_atoll(const char *str);
char				**ft_split_spaces(char *str);
int					init_data(t_cub3d *data);

// read_map:
int					read_file_and_parse(char **argv, t_cub3d *data);
int					check_splitptr_len(char **splitted_line);
char				*join_splitted_line(char **splitted_line);
int					check_texture_path(t_cub3d *data, int current);
int					add_new_node_to_map(char *line, t_cub3d *data);
int					get_raw_map(t_cub3d *data, int fd);
void				set_color_to_floor_ceiling(t_cub3d *data);
void				assign_player_map_dimension(t_cub3d *data, \
									char **map);
int					texture_color_init(char **splitted_line, t_cub3d *data);

// flood_fill:
int					flood_fill_inside_map(char **raw_map, t_cub3d *data);
int					flood_fill_outside_map(char **temp_map, t_cub3d *data);
int					allocate_temp_map(char ***temp_map, char **raw_map,
						int height, int width);
int					check_valid_line(char **map, int flag);

// check_validity:
int					check_valid_color(t_cub3d *data);
int					not_valid_line(char *current);
int					valid_map(t_cub3d *data);
int					check_amount_player(char **map, int index, t_cub3d *d);
int					check_character(char c, int flag);

// render:
void				hit_wall(t_cub3d *data);
double				fix_angle(double angle);
void				ray_casting(t_cub3d *data);
void				horizontal_vertical(t_cub3d *data);
int					init_window(t_cub3d *data);
void				render_game(t_cub3d *data);
void				draw_2d_map(t_cub3d *data);
void				draw_rayline(t_cub3d *data);
void				draw_2d_player(t_cub3d *data);
void				draw_2d_direction(t_cub3d *data);
void				render_background(t_cub3d *data);
void				draw_walls(t_cub3d *data, int screen_x);
double				degree_to_rad(double angle);
void				dda_algorithm(t_point p1, t_point p2, t_cub3d *data,
						t_line line);
void				clear_image(t_cub3d *data);
void				my_mlx_pixel_put(t_cub3d *data, double x, double y,
						unsigned int color);
void				my_mlx_pixel_put_mini(t_cub3d *data, double width,
						double height, unsigned int color);

//key_events
void				hook_keys_loop(t_cub3d *data);
void				move_keys(t_cub3d *data);
void				arrow_keys(t_cub3d *data);
void				update_player_coordinates(t_cub3d *data);

// ray
void				grid_to_pixel(t_cub3d *data);
bool				is_in_map(t_cub3d *data, double x, double y);
bool				is_not_wall(t_cub3d *data, double x, double y);
void				update_position(double *x, double *y, double angle,
						double distance);

#endif