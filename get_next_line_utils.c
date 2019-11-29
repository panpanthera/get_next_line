/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:19:38 by jpagacz           #+#    #+#             */
/*   Updated: 2019/11/28 15:35:11 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
	const char    *csrc;
	char        *cdst;
	size_t        i;

	csrc = src;
	cdst = dst;
	i = 0;
	if ((!src && !dst) || n == 0)
		return (dst);
	while (i < n)
	{
		*cdst++ = *csrc++;
		i++;
	}
	return (dst);
}

char    *ft_strdup(const char *s1)
{
	int        size;
	char    *s2;

	size = ft_strlen(s1) + 1;
	if (!(s2 = (char *)malloc((size) * sizeof(char))))
		return (NULL);
	s2 = ft_memcpy(s2, s1, size);
	return (s2);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char            *rval;
	unsigned int    i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		rval = ft_strdup("");
		return (rval);
	}
	if (!(rval = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < (ft_strlen(s) - start) && len > 0)
	{
		rval[i] = s[start + i];
		i++;
		len--;
	}
	rval[i] = '\0';
	return (rval);
}

static char    *ft_fill_join(char const *s1, char const *s2, int len1, int len2)
{
	int        i;
	int        j;
	char    *p;

	i = 0;
	j = 0;
	if (!(p = (char *)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	while (i < len1)
	{
		p[i] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (i < len2)
	{
		p[j] = s2[i];
		i++;
		j++;
	}
	p[j] = '\0';
	return (p);
}

char        *ft_strjoin(char const *s1, char const *s2)
{
	int        len1;
	int        len2;
	char    *rval;

	if (!s1 || !s2)
		return (NULL);
	rval = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	rval = ft_fill_join(s1, s2, len1, len2);
	return (rval);
}

char	*ft_strchr(const char *s, int c)
{
	int size;

	size = ft_strlen(s) + 1;
	while (size > 0)
	{
		if (*s == c)
			return ((char *)s);
		s++;
		size--;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
