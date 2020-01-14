/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:23:41 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/10 13:54:23 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *reste;
	char		*temp;
	int			i;
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	int size;

	i = 0;
	size = ft_strchr(reste, '\n');
	if (!(reste = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) || fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';

		if (ft_strchr(reste, '\n'))
			*line = ft_strndup(reste, i);
		while (reste[i] != '\n' && reste[i])
			i++;
		*line = ft_substr(reste, 0, i);
		reste = &reste[i + 1];
	}
	return (0);
}
