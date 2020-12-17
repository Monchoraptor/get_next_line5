/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:49 by amoracho          #+#    #+#             */
/*   Updated: 2020/12/16 22:17:29 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (&(s[i]));
		i++;
	}
	return (0);
}

void	save_line(char **cache, char **line)
{
	char	*aux;
	char	*aux2;
	char	*n;

//	printf("21\n");
	aux = ft_strdup(*cache);
	printf("22\n");
	//:printf("aux :%s\n", aux);
	if ((ft_strchr(*cache, '\n') != 0))
	{
		aux2 = ft_strdup(ft_strchr(*cache, '\n') + 1);
		printf("23\n");
		*(ft_strchr(aux, '\n')) = 0;
		printf("24\n");
		*line = ft_strdup(aux);
	}else {
		aux2 = 0;
		printf("25\n");
		*cache = aux2;
		printf("26\n");
	}
}

int checks(int fd, char **line, char **cache, char **buf)
{
	int	bytes_read;

	if (!(*buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!line || fd < 0 || BUFFER_SIZE <= 0 ||
		(bytes_read = read(fd, *buf, 0)) < 0)
	{
		free(*buf);
		*buf = NULL;
		return (-1);
	}
	if (!*cache)
		*cache = ft_strdup("");
	return (0);
}

void add_cache(char **cache, char **buf,char **aux, int bytes_read)
{
	(*buf)[bytes_read] = '\0';
//	printf("%s\n", *buf);
	*aux = ft_strjoin(*cache, *buf);
	free(*cache);
	*cache = *aux;
}

int	get_next_line(int fd, char **line)
{
	static char	*cache[4096];
	char		*buf;
	int			bytes_read;
	char		*aux;

	printf("11\n");
	if (checks(fd, line, &(cache[fd]), &buf) != 0)
		return (-1);
	printf("12\n");
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
//		printf("12\n");
		add_cache(&(cache[fd]), &buf, &aux, bytes_read);
//		printf("13\n");
		if (ft_strchr(cache[fd], '\n'))
			break ;
//		printf("14\n");
	}
	save_line(&(cache[fd]), line);

}
