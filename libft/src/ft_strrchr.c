/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:09:05 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/08/19 15:58:34 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	end;

	end = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[end]);
	while (end > 0)
	{
		end--;
		if (s[end] == (unsigned char)c)
			return ((char *)&s[end]);
	}
	return (NULL);
}
