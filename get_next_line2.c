/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:12:45 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/10 13:23:26 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *str;
	int i;
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) || fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else 
			str = ft_strjoin(str, buff);
		if (str[i])
		{
			while (str[i] != '\n' && str[i])
				i++;
			*line = ft_substr(str, 0, i);
			str = &str[i + 1];
			return (1);
		}
	}
	return (0);
}