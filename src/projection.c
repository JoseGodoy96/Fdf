/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 00:06:59 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/09/16 13:43:07 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	get_max_min(int x, int y, int z, t_camera *cam)
{
	double		sx;
	double		sy;

	sx = (x - y) * cos(cam->angle)
		* cam->shift_x;
	sy = (x + y) * sin(cam->angle)
		* cam->shift_y - z * cam->elevation;
	if (sx > cam->sx_max)
		cam->sx_max = sx;
	if (sx < cam->sx_m)
		cam->sx_m = sx;
	if (sy > cam->sy_max)
		cam->sy_max = sy;
	if (sy < cam->sy_m)
		cam->sy_m = sy;
}

static void	get_scale_offset(t_camera *cam)
{
	double	factor_w;
	double	factor_h;

	cam->width_model = cam->sx_max - cam->sx_m;
	cam->height_model = cam->sy_max - cam->sy_m;
	factor_w = (WIN_WIDTH - 2.0 * MARGIN) / cam->width_model;
	factor_h = (WIN_HEIGHT - 2.0 * MARGIN) / cam->height_model;
	cam->scale = fmin(factor_w, factor_h);
	cam->offset_x = (double)WIN_WIDTH / 2.0
		- (cam->sx_m + cam->sx_max) / 2 * cam->scale;
	cam->offset_y = (double)WIN_HEIGHT / 2.0
		- (cam->sy_m + cam->sy_max) / 2 * cam->scale;
}

static void	get_margin(t_map_3d *map, t_camera *cam)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			get_max_min(j, i, map->z_matrix[i][j], cam);
			j++;
		}
		i++;
	}
	get_scale_offset(cam);
}

static t_map_2d	get_point(int x, int y, int z, t_camera *cam)
{
	t_map_2d	point;
	double		sx;
	double		sy;

	sx = (x - y) * cos(cam->angle)
		* cam->shift_x;
	sy = (x + y) * sin(cam->angle)
		* cam->shift_y - z * cam->elevation;
	point.screen_x = (int)round(sx * cam->scale + cam->offset_x);
	point.screen_y = (int)round(sy * cam->scale + cam->offset_y);
	return (point);
}

t_map_2d	**project_map(t_map_3d *map, t_camera *cam)
{
	t_map_2d	**map_2d;
	int			i;
	int			j;

	map_2d = malloc(sizeof(t_map_2d *) * map->height);
	if (!map_2d)
		return (NULL);
	i = 0;
	if (cam->initialized == 0)
	{
		get_margin(map, cam);
		cam->initialized = 1;
	}
	while (i < map->height)
	{
		map_2d[i] = malloc(sizeof(t_map_2d) * map->width);
		j = 0;
		while (j < map->width)
		{
			map_2d[i][j] = get_point(j, i, map->z_matrix[i][j], cam);
			j++;
		}
		i++;
	}
	return (map_2d);
}
