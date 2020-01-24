/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:35:37 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/22 17:09:57 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    get_next_line(int fd, char **line)
{
	int				ret;
	int				i;
	char			*buf;
	static char		*reste;
	char			*tmp;
	char			*tmp2;

	i = 0;
	tmp = NULL;
	tmp2 = NULL;
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (!reste)
	{
		reste = malloc(sizeof(char) * 1);
		reste[0] = 0;
	}
	if (fd < 0 || BUFFER_SIZE < 0 || !line || (ret = read(fd, buf, 0) < 0))
		return (-1);
	while (!(ft_strchr(reste, '\n')) && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		/*if (reste == NULL)
		  reste = ft_strdup(buf);
		  else
		  {*/
		tmp = ft_strjoin(reste, buf);
		//free(reste);
		reste = tmp;
		//}
		/*if (ft_strchr(reste, '\n'))
		  break ;*/
	}
	if (ft_strchr(reste, '\n'))
	{
		while (reste[i] != '\n' && reste[i])
			i++;
		*line = ft_substr(reste, 0, i);
		tmp2 = ft_strdup(&reste[i + 1]);
		//	free(reste);
		reste = tmp2;
		return (1);
	}
	else if (reste[i] == '\n')
	{
		*line = ft_substr(reste, 0, i);
		tmp2 = ft_strdup(&reste[i + 1]);
		//free(reste);
		reste = tmp2;
		return (1);
	}
	else
	{
		*line = ft_strdup(reste);
		//	free(reste);
		reste = tmp2;
		return (0);
	}
	return (1);
}