void	render_background(t_cub3d *data)
{
	int	y;
	int	x;
	int	color;

	color = 0x58ABE5;
	y = -1;
	while (++y < Y)
	{
		x = -1;
		while (++x < X)
		{
			my_mlx_pixel_put(data, x, y, color);
		}
	}
}

void	render_map(t_cub3d *data, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < BLOCK_SIZE - 1)
	{
		j = -1;
		while (++j < BLOCK_SIZE - 1)
			my_mlx_pixel_put(data, x + j, y + i, color);
	}
}

static void	creat_player(t_cub3d *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < PLAYER_SIZE)
	{
		j = -1;
		while (++j < PLAYER_SIZE)
		{
			my_mlx_pixel_put(data, x + j, y + i, color);
		}
	}
}

void	render_2d_map(t_cub3d *data)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (x < (int)ft_strlen(data->raw_map[y]))
			{
				if (check_character(data->raw_map[y][x], 2))
					color = data->color[0];
				if (data->raw_map[y][x] == '1')
					color = data->color[1];
				if (data->raw_map[y][x] == '0')
					color = data->color[0];
			}
			render_map(data, x * BLOCK_SIZE, y * BLOCK_SIZE, color);
		}
	}
}

void	render_player(t_cub3d *data)
{
	int	y;
	int	x;
	int	color;

	y = data->player_y;
	while (y < data->height)
	{
		x = data->player_x;
		while (x < data->width)
		{
			if (x == data->player_x && y == data->player_y)
			{
				color = data->color[2];
				creat_player(data, x * BLOCK_SIZE + BLOCK_SIZE / 2, y * BLOCK_SIZE + BLOCK_SIZE / 2, color);
				break ;
			}
			x++;
		}
		y++;
	}
}


void	my_mlx_pixel_put(t_cub3d *data, int x, int y, unsigned int color)
{
	char	*dst;

	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	dst = data->img->addr + (y * data->img->line_length + \
	x * (data->img->bits_per_pixel
				/ 8));
	if ((x >= 0 && x < X) && (y >= 0 && y < Y))
		*(unsigned int *)dst = color;
}


int	mouse_handler(t_cub3d *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	free_texture(data);
	exit(0);
}

static void	move(t_cub3d *data, int height, int width)
{
	if (data->raw_map[height / 2][width / 2] == '1')
		return ;
	else
	{
		data->player_x = width;
		data->player_y = height;
		mlx_clear_window(data->mlx_ptr, data->mlx_window);
		image_handler(data);
	}
}

void	moving_keys(int key, t_cub3d *data)
{
	if (key == 13) //w key
		data->tmp_player_y--;
	if (key == 1) //S
		data->tmp_player_y++;
	if (key == 0) // A
		data->tmp_player_x--;
	if (key == 2) //D
		data->tmp_player_x++;
}

int	key_handler(int key, t_cub3d *data)
{
	data->tmp_player_x = data->player_x;
	data->tmp_player_y = data->player_y;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		free_texture(data);
		exit(0);
	}
	if (key == 13 || key == 0 || key == 1 || key == 2)
	{
		moving_keys(key, data);
		if (data->player_x * 2 != data->tmp_player_x || \
		data->player_y * 2 != data->tmp_player_y)
		move(data, data->tmp_player_y, data->tmp_player_x);
	}
	return (0);
}