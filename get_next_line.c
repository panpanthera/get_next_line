/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:19:44 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/14 14:35:25 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			ret;
	int			i;
	char		buf[BUFFER_SIZE + 1];
	static char	*reste;
	char		*tmp;
	char		*tmp2;

	i = 0;
	tmp = 0;
	tmp2 = 0;
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	while (ft_strchr(buf, '\n') == -1 && ret)
	{	
		ret = read(fd, buf, BUFFER_SIZE);	
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
