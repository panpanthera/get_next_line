/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:19:44 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/07 16:23:58 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int ret;
	char buf[BUFFER_SIZE + 1];
	static char *s;
	char *tmp = 0;

	if (fd < 0 || !line)
		return (-1);
	else 
	{
		while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[ret] = '\0';
			if (!s)
				s = ft_strdup(buf);
			else
			{
				tmp = ft_strjoin(s, buf);
				free(s);
				s = tmp;
			}
			if (*s != '\n' && *s)
				*line = ft_strdup(s);
		}
		return (1);
	}
	return (0);
}
