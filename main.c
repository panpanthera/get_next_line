/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:38:24 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/14 12:57:03 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   main(int ac, char **av)
{
	char  *line;
	int   fd;
	int		nbline = 0;

	(void)ac;
	if (!(fd = open(av[1], O_RDONLY)))
		return (1);
	while (get_next_line(fd, &line) == 1)
	{
		printf("[%d][%s]\n", ++nbline, line);
		free(line);
	}
	printf("[%d][%s]\n", ++nbline, line);
	free(line);
	return (0);
}
