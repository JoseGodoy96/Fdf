/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:54:19 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/25 16:51:15 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_parsing(char *argv)
{
	char	*fdf;
	int		len;
	int		finish;

	fdf = ".fdf";
	len = ft_strlen(argv);
	finish = 3;
	if (len < 4)
		error_exit("FILE ERROR");
	len--;
	while (finish >= 0)
	{
		if (argv[len] != fdf[finish])
			error_exit("FILE ERROR");
		len--;
		finish--;
	}
}

int	validator_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	value;

	i = 0;
	sign = 1;
	value = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = value * 10 + (nptr[i] - '0');
		if ((value * sign) > INT_MAX || (value * sign) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

void	validate_nums(int fd, t_map_3d *map)
{
	char	*line;
	char	**nums;
	int		val;
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
			val = validator_atoi(nums[i]);
			if (val == 1)
				map->validate = 1;
			i++;
		}
		ft_free(nums, line);
		line = get_next_line(fd);
		j++;
	}
}

void	ft_parse_values(char *file, t_map_3d *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	validate_nums(fd, map);
	close(fd);
}
