/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:35:37 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/24 12:19:48 by jpagacz          ###   ########.fr       */
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

	int			size;
	char		*buf;
	char		*tmp;
	static char	*left;

	tmp = NULL;
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (!left)
	{
		if(!(left = malloc(sizeof(char) * 1)))
			return (-1);
		left[0] = 0;
	}
	if (fd < 0 || BUFFER_SIZE < 0 || !line || (size = read(fd, buf, 0) < 0))
		return (-1);
	while ((ft_strchr(left, '\n') == -1)
			&& (size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		if(!(left = ft_strjoin(left, buf)))
			return (-1);
	}
	free(buf);
	if (size < 0)
		return (-1);
	if (size == 0 && (left == NULL || left == '\0'))
	{	
		if (!(*line = ft_strdup("")))
			return (-1);
		ft_del(&left);
		return (0);
	}
	if ((size = ft_strchr(left, '\n')) > -1)
	{
		if (!(*line = ft_substr(left, 0, size)))
			return (-1);
		if (!(tmp = ft_strdup(&left[size + 1])))
			return (-1);
		ft_del(&left);
		left = tmp;
		return (1);
	}
	if (!(*line = ft_strdup(left)))
		return (-1);
	ft_del(&left);
	return (0);
}

/*#include "get_next_line.h"

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

 int			size;
 char		*buf;
 char		*tmp;
 static char	*left;

 tmp = NULL;
 if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
 return (-1);
 if (!left)
 {
 left = malloc(sizeof(char) * 1);
 left[0] = 0;
 }
 if (fd < 0 || BUFFER_SIZE <= 0 || !line || (size = read(fd, buf, 0) < 0))
 return (-1);
 while ((ft_strchr(left, '\n') == -1)
 && (size = read(fd, buf, BUFFER_SIZE)) > 0)
 {
 buf[size] = '\0';
 left = ft_strjoin(left, buf);
 return (-1);
 }
 free(buf);
 if (size < 0)
 return (-1);
 if (size == 0 && (left == NULL || left == '\0'))
 {	
		if (!(*line = ft_strdup("")))
			return (-1);
		ft_del(&left);
		return (0);
	}
	if ((size = ft_strchr(left, '\n')) > -1)
	{
		if (!(*line = ft_substr(left, 0, size)))
			return (-1);
		if(!(tmp = ft_strdup(&left[size + 1])))
			return (-1);
		ft_del(&left);
		left = tmp;
		return (1);
	}
	*line = ft_strdup(left);
	ft_del(&left);
	return (0);
}*/
