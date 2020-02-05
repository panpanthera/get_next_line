/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:36:33 by jpagacz           #+#    #+#             */
/*   Updated: 2020/02/05 13:11:22 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(char *s1);
char    *ft_substr(char *s, unsigned int start, size_t len);
char        *ft_strjoin(char *s1, char *s2);
int			ft_strchr(char *s, int c);

#endif
