/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:51:16 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/21 16:52:05 by jpagacz          ###   ########.fr       */
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
