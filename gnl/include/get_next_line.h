/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:03:31 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/09/05 20:03:17 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif 

char			*get_next_line(int fd);
char			*ft_extract_line(char *save);
char			*ft_update_save(char *save);
size_t			ft_strlen(const char *s);
char			*gnl_strjoin(char *s1, char *s2);
char			*gnl_strchr(const char *s, int c);
char			*gnl_strdup(char *s);
char			*ft_initialsave(char *save);

#endif
