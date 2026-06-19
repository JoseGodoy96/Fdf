/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:11:18 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/25 17:16:48 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
angle->map angle
shift_x->no movement in x
shift_y->no movement in y
elevation->map elevation
scale->zoom
offset_x->manual user offset
offset_x->manual user offset
sx_m->minimum x
sx_max->maximum x
sy_max->maximum y
sy_m->minimum y
with_model->map's with unit
height_model->map's height
initialized->to check if the camera is initialized
*/
t_camera	*init_camera(void)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	cam->angle = PI / 6.0;
	cam->shift_x = 1.0;
	cam->shift_y = 1.0;
	cam->elevation = 1.0;
	cam->scale = 0;
	cam->offset_x = 0;
	cam->offset_y = 0;
	cam->sx_max = -INFINITY;
	cam->sx_m = INFINITY;
	cam->sy_max = -INFINITY;
	cam->sy_m = INFINITY;
	cam->width_model = 0;
	cam->height_model = 0;
	cam->initialized = 0;
	return (cam);
}
