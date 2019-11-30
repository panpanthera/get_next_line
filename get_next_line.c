/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:19:44 by jpagacz           #+#    #+#             */
/*   Updated: 2019/11/30 16:14:55 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int ret;
	char buf[BUFFER_SIZE + 1];
	static char *s = 0;
	char *tmp = 0;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!s)
			s = ft_strdup(buf);
		else
		{
			//ou s = ft_strjoin(s, buf) sans oublier de free strjoin avant son return) et donc sans tmp;
			tmp = ft_strjoin(s, buf);
			free(s);
			s = tmp;
		}
		if (ft_strchr(s, '\n'))
		{
			line[ret] = ft_strdup(s);
			tmp = ft_strdup(s);
			free(s);
			s = tmp;
			break ;
		}
	}

	if (ret == 0 && !s)
		return (0);
	if (ret <  0)
		return (-1);

	return (0);
}
