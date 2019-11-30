/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpagacz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:38:24 by jpagacz           #+#    #+#             */
/*   Updated: 2019/11/30 15:52:53 by jpagacz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   main(int ac, char **av)
{
	char  *line;
	int   fd1;
	int i;

	(void)ac;
	i = 30;
	fd1 = open(av[1], O_RDONLY);
	while (i > 0)
	{
		get_next_line(fd1, &line);
		printf("%s\n", line);
		i--;
	}
	return (0);
}
