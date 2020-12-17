/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:49 by amoracho          #+#    #+#             */
/*   Updated: 2020/12/17 22:19:42 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	save_line(char **cache, char **line)
{
	char	*aux;

	aux = ft_strdup(*cache);
	aux[ft_strchr(aux, '\n') - aux] = '\0';
	*line = ft_strdup(aux);
	free(aux);
}

int		checks(int fd, char **line, char **cache, char **buf)
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

void	add_cache(char **cache, char **buf, char **aux, int bytes_read)
{
	(*buf)[bytes_read] = '\0';
	*aux = ft_strjoin(*cache, *buf);
	free(*cache);
	*cache = *aux;
}

void	update_cache(char **cache)
{
	char	*aux;

	aux = ft_strdup(ft_strchr(*cache, '\n') + 1);
	free(*cache);
	*cache = aux;
}

int		get_next_line(int fd, char **line)
{
	static char	*cache[4096];
	char		*buf;
	int			bytes_read;
	char		*aux;

	if (checks(fd, line, &(cache[fd]), &buf) != 0)
		return (-1);
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)))
	{
		add_cache(&(cache[fd]), &buf, &aux, bytes_read);
		if (ft_strchr(cache[fd], '\n'))
			break ;
	}
	if (!ft_strchr(cache[fd], '\n'))
	{
		*line = ft_strdup(cache[fd]);
		free(cache[fd]);
		free(buf);
		return (0);
	}
	save_line(&(cache[fd]), line);
	update_cache(&(cache[fd]));
	free(buf);
	return (1);
}
