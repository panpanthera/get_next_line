/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:38:24 by jpagacz           #+#    #+#             */
/*   Updated: 2020/01/07 15:09:42 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   main(int ac, char **av)
{
	char  *line;
	int   fd1;

	(void)ac;
	if (!(fd1 = open(av[1], O_RDONLY)))
		return (1);
	while (get_next_line(fd1, &line) == 1)
		printf("[%s]\n", line);
	return (0);
}
