/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:35:37 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/23 16:49:06 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_del(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int    get_next_line(int fd, char **line)
{

	int			ret;
	char		*buf;
	char		*tmp;
	static char	*reste;

	tmp = NULL;
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (!reste)
	{
		reste = malloc(sizeof(char) * 1);
		reste[0] = 0;
	}
	if (fd < 0 || BUFFER_SIZE < 0 || !line || (ret = read(fd, buf, 0) < 0))
		return (-1);
	while ((ft_strchr(reste, '\n') == -1)
			&& (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		reste = ft_strjoin(reste, buf);
	}
	free(buf);
	if (ret < 0)
		return (-1);
	if (ret == 0 && (reste == NULL || reste == '\0'))
	{	
		*line = ft_strdup("");
		ft_del(&reste);
		return (0);
	}
	if ((ret = ft_strchr(reste, '\n')) > -1)
	{
		*line = ft_substr(reste, 0, ret);
		tmp = ft_strdup(&reste[ret + 1]);
		ft_del(&reste);
		reste = tmp;
		return (1);
	}
	*line = ft_strdup(reste);
	ft_del(&reste);
	return (0);
}
