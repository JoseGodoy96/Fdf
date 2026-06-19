/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:33:36 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/09/17 13:06:30 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	flag;

	count = 0;
	i = 0;
	flag = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 1;
		if (s[i] != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

static void	ft_copymatrix(char **matrix, char const *s, char c, size_t k)
{
	size_t	flag;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	flag = 1;
	while (s[k] != '\0')
	{
		if (s[k] != c)
		{
			matrix[i][j++] = s[k];
			flag = 0;
		}
		if (s[k] == c && flag == 0)
		{
			matrix[i++][j] = '\0';
			j = 0;
			flag = 1;
		}
		k++;
	}
	if (flag == 0)
		matrix[i][j] = '\0';
}

static char	**ft_finalasig(char **matrix, size_t i, size_t count)
{
	if (count != 0)
	{
		matrix[i] = malloc(sizeof(char) * (count + 1));
		if (matrix[i] == NULL)
			return (NULL);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

static char	**ft_asigmatrix(char **matrix, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[j] != '\0')
	{
		if (s[j] == c && count != 0)
		{
			matrix[i] = malloc(sizeof(char) * (count + 1));
			if (matrix[i] == NULL)
				return (NULL);
			count = 0;
			i++;
		}
		if (s[j] != c)
			count++;
		j++;
	}
	ft_finalasig(matrix, i, count);
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	size;
	size_t	k;

	k = 0;
	size = ft_count(s, c);
	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	if (matrix == NULL)
		return (NULL);
	if (size == 0)
	{
		matrix[0] = NULL;
		return (matrix);
	}
	ft_asigmatrix(matrix, s, c);
	ft_copymatrix(matrix, s, c, k);
	return (matrix);
}
