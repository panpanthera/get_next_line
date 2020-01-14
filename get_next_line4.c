/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:35:37 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/14 15:52:25 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    get_next_line(int fd, char **line)
{
	int				ret;
	int				i;
	char			buf[BUFFER_SIZE + 1];
	static char		*reste;
	char			*tmp;
	char			*tmp2;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (reste == NULL)
			reste = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(reste, buf);
			free(reste);
			reste = tmp;
		}
	}
	if (reste[i])
	{
		while (reste[i] != '\n' && reste[i])
			i++;
		*line = ft_substr(reste, 0, i);
		tmp2 = ft_strdup(&reste[i + 1]);
		if (ft_strchr(reste, '\n') == 1)
		{
			free(reste);
			reste = tmp2;
			return (1);
		}
		else
		{
			free(reste);
			reste = tmp2;
			return (0);
		}
	}
	return (0);
}
