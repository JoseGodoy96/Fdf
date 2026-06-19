/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:23:37 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/09/05 20:03:59 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/include/get_next_line.h"

char	*ft_initialsave(char *save)
{
	if (!save)
	{
		save = gnl_strdup("");
		if (!save)
			return (NULL);
	}
	return (save);
}

char	*ft_containtext(int fd, char *save)
{
	char	*buffer;
	ssize_t	bytes;

	save = ft_initialsave(save);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(save);
		return (NULL);
	}
	bytes = 1;
	while (!gnl_strchr(save, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(save);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		save = gnl_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*ft_extract_line(char *save)
{
	char	*line;
	size_t	i;

	line = (char *)malloc(sizeof(char) * (ft_strlen(save) + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_update_save(char *save)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (save[i] != '\0')
		new[j++] = save[i++];
	new[j] = '\0';
	free(save);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_containtext(fd, save);
	if (!save || save[0] == '\0')
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = ft_extract_line(save);
	save = ft_update_save(save);
	return (line);
}
