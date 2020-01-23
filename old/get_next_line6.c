/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 09:22:04 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/21 09:36:35 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int ret;
	int i;
	char	buf[BUFFER_SIZE + 1];
	static char	*reste;
	char	*tmp;

	i = 0;
	if (BUFFER_SIZE < 0 || fd < 0 || !line)
		return (-1);
	while((ft_strchr(buf, '\n') == -1) && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(reste, buf);
		free(reste);
		reste = tmp;
	}
	while (reste[i] && reste[i] != '\n')
		i++;
	*line = ft_substr(reste, 0, i);
	if (reste[i] == '\n')
		tmp = ft_strdup(&reste[i + 1]);
	free(reste);
	reste = tmp;
	return (1);

}
