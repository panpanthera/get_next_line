/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:51:16 by jpagacz           #+#    #+#             */
/*   Updated: 2020/02/05 11:45:46 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	char *line;
	char *line1;
	int fd;
	int fd1;

	(void)ac;	
	if (!(fd = open(av[1], O_RDONLY)))
		return (1);
        if (!(fd1 = open(av[2], O_RDONLY)))
                return (1);
	while (get_next_line(fd, &line) == 1)
	{
		printf("[%s]\n", line);
		free(line);
	}
	printf("[%s]\n", line);
	free(line);
	 while (get_next_line(fd1, &line1) == 1)
        {
                printf("[%s]\n", line1);
                free(line1);
        }
	printf("[%s]\n", line1);
	free(line1);
	return(0);
}

/*int   main(int ac, char **av)
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
}*/
