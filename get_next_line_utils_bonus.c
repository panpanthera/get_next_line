/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:19:38 by jpagacz           #+#    #+#             */
/*   Updated: 2020/02/05 16:22:08 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char    *ft_strdup(char *s1)
{
	size_t	i;
	char    *s2;

	if (!(s2 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*s1)
		s2[i++] = *s1++;
	s2[i] = '\0';
	return (s2);
}


char    *ft_substr(char *s, unsigned int start, size_t len)
{
	char            *rval;
	unsigned int    i;

	i = start;
	if (!s)
		return (NULL);
	if (i  > ft_strlen(s))
		return (NULL);
	if (!(rval = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[start] && len)
	{
		rval[i++] = s[start++];
		len--;
	}
	rval[i] = '\0';
	return (rval);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}



int			ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}
