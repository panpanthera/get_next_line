/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:45:09 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/18 18:10:14 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	while (ft_strchr(buf, '\n') == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		printf("buf = %s\n", buf);
		*line = ft_substr(buf, 0, i);
		i++;
	}

//	*line = ft_substr(buf, 0, i);
	return (0);
}

