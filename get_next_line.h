/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:22:18 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/07 14:56:55 by jpagacz          ###   ########.fr       */
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

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strnew(size_t size);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strcpy(char *dst, const char *src);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
void		ft_memdel(void **ap);
void		ft_strdel(char **as);

#endif
