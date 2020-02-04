/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:28:43 by jpagacz           #+#    #+#             */
/*   Updated: 2020/02/04 18:12:42 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_del(char **str)
{
	free(*str);
	*str = NULL;
}

int			get_next_line(int fd, char **line)
{
	int			size;
	char		*buf;
	char		*tmp;
	static char	*left[OPEN_MAX];

	tmp = NULL;
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (!left[fd])
	{
		if (!(left[fd] = ft_strdup("")))
			return (-1);
	}
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 0
			|| !line || (size = read(fd, buf, 0) < 0))
		return (-1);
	while ((ft_strchr(left[fd], '\n') == -1)
			&& (size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		if (left[fd] == NULL)
		{
			if(!(left[fd] = ft_strdup(buf)))
				return(-1);
		}
		else
		{
			if (!(tmp = ft_strjoin(left[fd], buf)))
				return (-1);
			ft_del(&left[fd]);
			left[fd] = tmp;
		}
	}
	ft_del(&buf);

	if (size < 0)
		return (-1);
	if (size == 0 && (left[fd] == NULL || left[fd] == '\0'))
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		free(left[fd]);
		return (0);
	}
	if ((size = ft_strchr(left[fd], '\n')) > -1)
	{
		if (!(*line = ft_substr(left[fd], 0, size)))
			return (-1);
		if (!(tmp = ft_strdup(&left[fd][size + 1])))
			return (-1);
		ft_del(&left[fd]);
		left[fd] = tmp;
		return (1);
	}
	if (!(*line = ft_strdup(left[fd])))
		return (-1);
	ft_del(&left[fd]);
	return (0);
}
