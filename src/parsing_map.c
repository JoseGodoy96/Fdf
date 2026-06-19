/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:17:03 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/25 17:07:25 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_get_width(char *line)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 1;
	count = 0;
	while (line[i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9') && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (line[i] == ' ')
			flag = 1;
		i++;
	}
	return (count);
}

static void	ft_get_height(char *file, t_map_3d *map)
{
	int		fd;
	char	*line;
	int		cmp_width;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map->width == 0)
			map->width = ft_get_width(line);
		cmp_width = ft_get_width(line);
		if (map->width != cmp_width)
			map->width = -1;
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	ft_print_matrix(int fd, t_map_3d *map)
{
	char	*line;
	char	**nums;
	int		i;
	int		j;

	j = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		nums = ft_split(line, ' ');
		i = 0;
		while (i < map->width)
		{
			map->z_matrix[j][i] = ft_atoi(nums[i]);
			i++;
		}
		ft_free(nums, line);
		line = get_next_line(fd);
		j++;
	}
}

static void	ft_get_z_matrix(char *file, t_map_3d *map)
{
	int		fd;
	int		i;

	i = 0;
	map->z_matrix = malloc(sizeof(int *) * map->height);
	if (map->height < 1 || map->width < 1 || !map->z_matrix)
	{
		free(map->z_matrix);
		free(map);
		return ;
	}
	i = 0;
	while (i < map->height)
	{
		map->z_matrix[i] = malloc(sizeof(int) * map->width);
		i++;
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	ft_print_matrix(fd, map);
	close(fd);
}

t_map_3d	*read_map(char	*file)
{
	t_map_3d	*map;

	map = malloc(sizeof(t_map_3d));
	if (!map)
		return (NULL);
	map->validate = 0;
	map->height = 0;
	map->width = 0;
	ft_get_height(file, map);
	ft_parse_values(file, map);
	if (map->validate == 1)
	{
		free(map);
		return (NULL);
	}
	ft_get_z_matrix(file, map);
	return (map);
}
