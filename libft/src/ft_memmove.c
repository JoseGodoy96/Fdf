/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:31:25 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/08/19 16:00:23 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;
	size_t				i;

	a = (unsigned char *)dest;
	b = (const unsigned char *)src;
	if (!a && !b)
		return (NULL);
	if (b < a)
	{
		i = n;
		while (i > 0)
		{
			i--;
			a[i] = b[i];
		}
	}
	else
		ft_memcpy(a, b, n);
	return (a);
}
