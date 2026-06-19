/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:01:41 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/24 22:07:01 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../gnl/include/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

// Macros for screen
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define MARGIN 100
# define PI 3.14159265

// Keys macros 
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_PLUS_ALT 43
# define KEY_MINUS_ALT 45 
# define KEY_RESET 114

// struct for parsing .fdf
typedef struct s_map_3d
{
	int	validate;
	int	width;
	int	height;
	int	**z_matrix;
}	t_map_3d;

// struct for a 2d point
typedef struct s_map_2d
{
	int	screen_x;
	int	screen_y;
}	t_map_2d;

// struct for camera values
typedef struct s_camera
{
	double	angle;
	int		shift_x;
	int		shift_y;
	float	elevation;
	int		scale;
	int		offset_x;
	int		offset_y;
	double	sx_max;
	double	sx_m;
	double	sy_max;
	double	sy_m;
	double	width_model;
	double	height_model;
	int		initialized;
}	t_camera;

// Variables for bresenham algorithm
typedef struct s_variable
{
	int	dx;
	int	dy;
	int	y;
	int	x;
	int	i;
	int	p;
	int	dir;
	int	tmp;
}	t_v;

// struct for fdf
typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_map_3d	*map;
	t_camera	*cam;
	t_map_2d	**map_2d;
}	t_fdf;

// main.c
int			error_exit(char *msg);
// parsing_init.c
void		init_parsing(char *argv);
int			validator_atoi(const char *nptr);
void		validate_nums(int fd, t_map_3d *map);
void		ft_parse_values(char *file, t_map_3d *map);
// algorithm.c
void		drawline_h(t_fdf *fdf, t_map_2d p0, t_map_2d p1, int color);
void		drawline_v(t_fdf *fdf, t_map_2d p0, t_map_2d p1, int color);
// camera.c
t_camera	*init_camera(void);
// draw.c
void		putpixel(t_fdf *fdf, int x, int y, int color);
void		algorith_bresenham(t_fdf *fdf, t_map_2d p0, t_map_2d p1, int color);
void		draw_map(t_fdf *fdf, t_map_2d **map_2d);
// hooks.c
int			close_hook_window(void *fdf);
int			key_hook(int keycode, t_fdf *fdf);
// parsing_map.c
t_map_3d	*read_map(char	*file);
// projection.c
t_map_2d	**project_map(t_map_3d *map, t_camera *cam);
// utils.c
void		ft_free(char **matrix, char *line);
void		free_map3d(t_map_3d *map);
void		free_map(t_map_2d **map_2d, int height, int width);

#endif