/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:28:43 by jpagacz           #+#    #+#             */
/*   Updated: 2020/02/11 11:23:49 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_del(char **str)
{
	free(*str);
	*str = NULL;
}

int			ft_printline(char **stock, char **line, int fd)
{
	int		size;
	char	*tmp;

	tmp = NULL;
	if ((size = ft_strchr(stock[fd], '\n')) > -1)
	{
		if (!(*line = ft_substr(stock[fd], 0, size)))
		{
			ft_del(&stock[fd]);
			return (-1);
		}
		if (!(tmp = ft_strdup(&stock[fd][size + 1])))
			return (-1);
		ft_del(&stock[fd]);
		stock[fd] = tmp;
		return (1);
	}
	if (!(*line = ft_strdup(stock[fd])))
		return (-1);
	ft_del(&stock[fd]);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*stock[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1
			|| !line || (size = read(fd, buf, 0) < 0)
			|| (!stock[fd] && !(stock[fd] = ft_strdup(""))))
		return (-1);
	while ((ft_strchr(stock[fd], '\n') == -1)
			&& (size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		if (!stock[fd] && !(stock[fd] = ft_strdup(buf)))
		{
			free(stock[fd]);
			return (-1);
		}
		else if (!(tmp = ft_strjoin(stock[fd], buf)))
			return (-1);
		ft_del(&stock[fd]);
		stock[fd] = tmp;
	}
	return (ft_printline(stock, line, fd));
}
