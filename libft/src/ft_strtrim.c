/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:39:28 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/09/17 13:05:39 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

static int	ft_reversed(char const *s1, char const *set)
{
	int	i;
	int	end;
	int	r_count;

	i = 0;
	end = ft_strlen(s1) - 1;
	r_count = 0;
	while (end > 0 && set[i] != '\0')
	{
		if (s1[end] == set[i])
		{
			r_count++;
			end--;
			i = 0;
		}
		if (s1[end] != set[i])
			i++;
	}
	return (r_count);
}

static int	ft_counttrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;
	int	revers;
	int	size;

	size = ft_strlen(s1);
	i = 0;
	j = 0;
	count = 0;
	revers = ft_reversed(s1, set);
	while (s1[i] != '\0' && set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			count++;
			i++;
			j = 0;
		}
		if (s1[i] != set[j])
			j++;
	}
	if (size < (count + revers))
		return (size);
	return (count + revers);
}

static char	*ft_trim(char const *s1, char const *set, char *a, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i] != '\0' && set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		if (s1[i] != set[j])
			j++;
	}
	while (k <= (size - 1))
	{
		a[k] = s1[i + k];
		k++;
	}
	a[k] = '\0';
	return (a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	int		size;

	size = ft_strlen(s1) - ft_counttrim(s1, set);
	a = (char *)malloc(sizeof(char) * (size + 1));
	if (size == 0)
	{
		a[0] = '\0';
		return (a);
	}
	if (a == NULL)
		return (NULL);
	ft_trim(s1, set, a, size);
	return (a);
}
