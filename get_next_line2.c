/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:12:45 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/07 15:06:52 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		errorChecker(int fd, char **str, char **line)
{
	if (fd < 0 || !line)
		return (-1);
	if (!*str)
	{
		if(!(*str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	return (0);
}

char	*readline(char *str, int fd)
{
	char	buff[BUFFER_SIZE + 1];	
	int		ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char *str;
	int i;

	i = 0;
	if (errorChecker(fd, &str, line) == -1)
		return (-1);

	if (*str)
		ft_strcpy(*line, str);
	str = readline(str, fd);
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (i == 0)
			*line = ft_strdup("");
		else
		{
			*line = ft_substr(str, 0, i);
			str = &str[i + 1];
		}
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}
