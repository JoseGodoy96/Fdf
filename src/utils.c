/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:17:16 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/12 23:53:10 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_free(char **matrix, char *line)
{
	int	i;

	if (!matrix)
	{
		free(line);
		return ;
	}
	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	free(line);
}

void	free_map3d(t_map_3d *map)
{
	int	i;

	if (!map)
		return ;
	if (map->z_matrix)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->z_matrix[i]);
			i++;
		}
		free(map->z_matrix);
	}
	free(map);
}

void	free_map(t_map_2d **map_2d, int height, int width)
{
	int	i;

	(void)width;
	if (!map_2d)
		return ;
	i = 0;
	while (i < height)
	{
		free(map_2d[i]);
		i++;
	}
	free(map_2d);
}
