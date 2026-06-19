/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:47:10 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/08/19 16:00:27 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*b;
	unsigned char		*a;
	size_t				i;

	a = (unsigned char *)dest;
	b = (const unsigned char *)src;
	if (!a && !b)
		return (NULL);
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
