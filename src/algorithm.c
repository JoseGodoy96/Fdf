/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:00:14 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/09/07 19:53:32 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_v	*ft_init_var(void)
{
	t_v	*var;

	var = malloc(sizeof(t_v));
	if (!var)
		return (NULL);
	var->dx = 0;
	var->dy = 0;
	var->y = 0;
	var->x = 0;
	var->i = 0;
	var->p = 0;
	var->dir = 0;
	var->tmp = 0;
	return (var);
}

static void	condition_h(t_map_2d *p0, t_map_2d *p1, t_v *var)
{
	if (p0->screen_x > p1->screen_x)
	{
		var->tmp = p0->screen_x;
		p0->screen_x = p1->screen_x;
		p1->screen_x = var->tmp;
		var->tmp = p0->screen_y;
		p0->screen_y = p1->screen_y;
		p1->screen_y = var->tmp;
	}
	var->dx = p1->screen_x - p0->screen_x;
	var->dy = p1->screen_y - p0->screen_y;
	if (var->dy < 0)
		var->dir = -1;
	else
		var->dir = 1;
	var->dy = var->dy * var->dir;
}

void	drawline_h(t_fdf *fdf, t_map_2d p0, t_map_2d p1, int color)
{
	t_v	*var;

	var = ft_init_var();
	condition_h(&p0, &p1, var);
	if (var->dx != 0)
	{
		var->y = p0.screen_y;
		var->i = 0;
		var->p = 2 * var->dy - var->dx;
		while (var->i <= var->dx)
		{
			putpixel(fdf, p0.screen_x + var->i, var->y, color);
			if (var->p >= 0)
			{
				var->y += var->dir;
				var->p = var->p + 2 * var->dy - 2 * var->dx;
			}
			else
				var->p = var->p + 2 * var->dy;
			var->i++;
		}
	}
	free(var);
}

static void	condition_v(t_map_2d *p0, t_map_2d *p1, t_v *var)
{
	if (p0->screen_y > p1->screen_y)
	{
		var->tmp = p0->screen_y;
		p0->screen_y = p1->screen_y;
		p1->screen_y = var->tmp;
		var->tmp = p0->screen_x;
		p0->screen_x = p1->screen_x;
		p1->screen_x = var->tmp;
	}
	var->dx = p1->screen_x - p0->screen_x;
	var->dy = p1->screen_y - p0->screen_y;
	if (var->dx < 0)
		var->dir = -1;
	else
		var->dir = 1;
	var->dx = var->dx * var->dir;
}

void	drawline_v(t_fdf *fdf, t_map_2d p0, t_map_2d p1, int color)
{
	t_v	*var;

	var = ft_init_var();
	condition_v(&p0, &p1, var);
	if (var->dy != 0)
	{
		var->x = p0.screen_x;
		var->i = 0;
		var->p = 2 * var->dx - var->dy;
		while (var->i <= var->dy)
		{
			putpixel(fdf, var->x, p0.screen_y + var->i, color);
			if (var->p >= 0)
			{
				var->x += var->dir;
				var->p = var->p + 2 * var->dx - 2 * var->dy;
			}
			else
				var->p = var->p + 2 * var->dx;
			var->i++;
		}
	}
	free(var);
}
