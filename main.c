/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:18:32 by mmartin-          #+#    #+#             */
/*   Updated: 2020/12/17 22:31:26 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		status;
	char	*line;

	fd = open("empty_lines", O_RDONLY);
	while ((status = get_next_line(fd, &line)) == 1)
	{
		printf("%.16p | %s\n", line, line);
		free(line);
	}
	if (status == 0)
		free(line);
	system("leaks a.out");
}

