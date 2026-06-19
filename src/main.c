/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:16:59 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/25 17:06:33 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	error_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

static void	pre_init(t_fdf *fdf, char *argv[])
{
	init_parsing(argv[1]);
	fdf->map = NULL;
	fdf->cam = NULL;
	fdf->img = NULL;
	fdf->addr = NULL;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->map_2d = NULL;
}

static void	init_fdf(t_fdf *fdf, int argc, char *argv[])
{
	pre_init(fdf, argv);
	if (argc != 2)
		error_exit("Error: more than one argument");
	fdf->map = read_map(argv[1]);
	if (!fdf->map)
		error_exit("Error: on the read of the map");
	fdf->cam = init_camera();
	if (!fdf->cam)
	{
		free_map3d(fdf->map);
		error_exit("Error: initialiting the cam");
	}
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		free_map3d(fdf->map);
		free(fdf->cam);
		error_exit("Error: initialiting the mlx");
	}
}

int	main(int argc, char *argv[])
{
	t_fdf		fdf;

	init_fdf(&fdf, argc, argv);
	fdf.win = mlx_new_window(fdf.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (!fdf.win)
	{
		free_map3d(fdf.map);
		free(fdf.cam);
		free(fdf.mlx);
		error_exit("Error: initialiting the window");
	}
	fdf.map_2d = project_map(fdf.map, fdf.cam);
	if (!fdf.map_2d)
	{
		if (fdf.win && fdf.mlx)
			mlx_destroy_window(fdf.mlx, fdf.win);
		free_map3d(fdf.map);
		free(fdf.cam);
		error_exit("Error: on the projection of the map");
	}
	draw_map(&fdf, fdf.map_2d);
	mlx_key_hook(fdf.win, key_hook, &fdf);
	mlx_hook(fdf.win, 17, 0L, close_hook_window, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
