/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:35:38 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/09/18 10:07:05 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

static long int	ft_counter(int n)
{
	long int	counter;
	long int	value;

	value = n;
	counter = 0;
	if (value == 0)
		counter = 1;
	if (value < 0)
	{
		counter = 1;
		value = -value;
	}
	while (value > 0)
	{
		value = value / 10;
		counter = counter + 1;
	}
	return (counter);
}

static char	*ft_sort(char *a)
{
	size_t	start;
	size_t	end;
	size_t	temp;

	start = 0;
	if (a[start] == '-')
		start++;
	end = (ft_strlen(a) - 1);
	while (start < end)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
	return (a);
}

static char	*ft_print(char *a, int n)
{
	long int	value;
	size_t		i;

	value = n;
	i = 0;
	if (value == 0)
	{
		a[i] = '0';
		i++;
	}
	if (value < 0)
	{
		value = -value;
		a[i] = '-';
		i++;
	}
	while (value > 0)
	{
		a[i] = (value % 10) + '0';
		value = value / 10;
		i++;
	}
	a[i] = '\0';
	ft_sort(a);
	return (a);
}

char	*ft_itoa(int n)
{
	char		*a;
	size_t		size;

	size = ft_counter(n);
	a = (char *)malloc(sizeof(char) * (size + 1));
	if (a == NULL)
		return (NULL);
	ft_print(a, n);
	return (a);
}
