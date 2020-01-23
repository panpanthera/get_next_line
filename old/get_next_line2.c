/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:12:45 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/18 16:32:12 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *str;
	int i;
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) || fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else 
			str = ft_strjoin(str, buf);
	}
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		*line = ft_substr(str, 0, i);
		str = &str[i + 1];
		return (1);
	}
return (0);
}
