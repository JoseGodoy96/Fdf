/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:47:51 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/09/17 13:05:04 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

static char	*ft_copystr(char const *s, unsigned int start, size_t len, char *a)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i == start)
		{
			while (s[i + j] != '\0' && j < len)
			{
				a[j] = s[i + j];
				j++;
			}
		}
		i++;
	}
	a[j] = '\0';
	return (a);
}

static size_t	ft_asigspace(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (i == start)
		{
			while (s[i + j] != '\0' && j < len)
			{
				j++;
				count++;
			}
		}
		i++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	size;

	size = ft_asigspace(s, start, len);
	a = (char *)malloc(sizeof(char) * (size + 1));
	if (a == NULL)
		return (NULL);
	if (size == 0)
	{
		a[0] = '\0';
		return (a);
	}
	ft_copystr(s, start, len, a);
	return (a);
}
