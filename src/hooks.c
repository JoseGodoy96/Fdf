/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:14:36 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/25 17:04:06 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	close_window(t_fdf *fdf)
{
	if (!fdf)
		return (0);
	if (fdf->mlx && fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->map_2d)
		free_map(fdf->map_2d, fdf->map->height, fdf->map->width);
	if (fdf->map)
		free_map3d(fdf->map);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	exit(0);
}

int	close_hook_window(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (!fdf)
		return (0);
	if (fdf->mlx && fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->map_2d)
		free_map(fdf->map_2d, fdf->map->height, fdf->map->width);
	if (fdf->map)
		free_map3d(fdf->map);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	exit(0);
}

static void	condition_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP)
		fdf->cam->offset_y -= 10;
	else if (keycode == KEY_DOWN)
		fdf->cam->offset_y += 10;
	else if (keycode == KEY_LEFT)
		fdf->cam->offset_x -= 10;
	else if (keycode == KEY_RIGHT)
		fdf->cam->offset_x += 10;
	else if (keycode == KEY_PLUS)
		fdf->cam->scale += 1;
	else if (keycode == KEY_MINUS)
		fdf->cam->scale -= 1;
	else if (keycode == KEY_PLUS_ALT)
		fdf->cam->elevation += 0.1;
	else if (keycode == KEY_MINUS_ALT)
		fdf->cam->elevation -= 0.1;
	else if (keycode == KEY_RESET)
	{
		if (fdf->cam)
			free(fdf->cam);
		fdf->cam = init_camera();
	}
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (!fdf)
		return (0);
	if (keycode == KEY_ESC)
		close_window(fdf);
	condition_key_hook(keycode, fdf);
	if (fdf->mlx && fdf->win)
		mlx_clear_window(fdf->mlx, fdf->win);
	if (!fdf->map || !fdf->map->height)
		return (0);
	if (fdf->map_2d)
		free_map(fdf->map_2d, fdf->map->height, fdf->map->width);
	fdf->map_2d = project_map(fdf->map, fdf->cam);
	ft_memset(fdf->addr, 0, WIN_HEIGHT * fdf->line_len);
	if (fdf->map_2d)
		draw_map(fdf, fdf->map_2d);
	return (0);
}
