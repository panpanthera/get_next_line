/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:19:44 by jpagacz           #+#    #+#             */
/*   Updated: 2019/11/28 20:25:11 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int ret;
	char buf[BUFFER_SIZE];
	static char *s;
	char *tmp;

	if (fd < 0 || !line)
		return (-1);
	while (*line != '\0' && ret == read(fd, buf, BUFFER_SIZE > 0))
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
	}
	if (ft_strchr(s, '\n'))
		return (1);
	if (ret == 0 && !s)
		return (0);
	if (ret <  0)
		return (-1);
}
