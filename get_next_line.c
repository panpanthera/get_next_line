/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:28:43 by jpagacz           #+#    #+#             */
/*   Updated: 2020/02/05 16:59:25 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line_utils.c"
#include "get_next_line.h"

static void	ft_del(char **str)
{
	free(*str);
	*str = NULL;
}

int			get_next_line(int fd, char **line)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*stock[FOPEN_MAX];

	tmp = NULL;	
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0
			|| !line || (size = read(fd, buf, 0) < 0))
		return (-1);
	if (!stock[fd])
	{
		if (!(stock[fd] = ft_strdup("")))
			return (-1);
	}
	while ((ft_strchr(stock[fd], '\n') == -1)
			&& (size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		if (stock[fd] == NULL)
		{
			if(!(stock[fd] = ft_strdup(buf)))
				return(-1);
		}
		else
		{
			if (!(tmp = ft_strjoin(stock[fd], buf)))
				return (-1);
			ft_del(&stock[fd]);
			stock[fd] = tmp;
		}
	}
	if (size < 0)
		return (-1);
	if (size == 0 && (stock[fd] == NULL || stock[fd] == '\0'))
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		free(stock[fd]);
		return (0);
	}
	if ((size = ft_strchr(stock[fd], '\n')) > -1)
	{
		if (!(*line = ft_substr(stock[fd], 0, size)))
			return (-1);
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
