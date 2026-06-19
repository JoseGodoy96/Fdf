/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:56:09 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/12 23:32:42 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	create_img(t_fdf *fdf)
{
	if (!fdf || !fdf->mlx)
		return (0);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img)
		return (0);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->line_len, &fdf->endian);
	return (1);
}

void	putpixel(t_fdf *fdf, int x, int y, int color)
{
	unsigned int	*pixel;

	if (!fdf || !fdf->mlx || !fdf->win || !fdf->addr)
		return ;
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = (unsigned int *)(fdf->addr
			+ (y * fdf->line_len + x * (fdf->bpp / 8)));
	*pixel = (unsigned int)color;
}

void	algorith_bresenham(t_fdf *fdf, t_map_2d p0, t_map_2d p1, int color)
{
	int	x;
	int	y;

	x = abs(p1.screen_x - p0.screen_x);
	y = abs(p1.screen_y - p0.screen_y);
	if (x > y)
		drawline_h(fdf, p0, p1, color);
	else
		drawline_v(fdf, p0, p1, color);
}

void	draw_map(t_fdf *fdf, t_map_2d **map_2d)
{
	int	i;
	int	j;

	if (!fdf->img)
		create_img(fdf);
	i = 0;
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			if (j < fdf->map->width - 1)
				algorith_bresenham(fdf, map_2d[i][j],
					map_2d[i][j + 1], 0xFFFFFF);
			if (i < fdf->map->height - 1)
				algorith_bresenham(fdf, map_2d[i][j],
					map_2d[i + 1][j], 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
