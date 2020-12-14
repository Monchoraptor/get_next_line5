/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:49 by amoracho          #+#    #+#             */
/*   Updated: 2020/12/13 18:02:12 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_empty(char **line)
{
	int i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}
//char	*duplicate(char *cache, int len)
//{
//	char	aux[len];
//	int		i;
//
//	i = 0;
//	while (i < len)
//	{
//		aux[i] = cache[i];
//	}
//	return (aux);
//}
int 	count_line(char *cache)
{
	int	i;

	i = 0;
	while ((cache[i] != '\n') && (cache[i] != '\0'))
		i++;
	if (cache[i] == '\n')
		return (i);
	return (i);
}

int		is_backslash_n(const char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (s[i++] == '\n')
			return (i - 1);
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char *cache;
	char buf[BUFFER_SIZE + 1];
	int i;
	char *aux;
	int bytes_read;

	if (!cache)
		cache = ft_strdup("");
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) == BUFFER_SIZE)
	{
		buf[bytes_read] = '\0';
		aux = ft_strjoin(cache, buf);
		free(cache);
		cache = aux;
		if (is_backslash_n(cache) > -1)
			break;
	}
	if ((i = is_backslash_n(cache)) > -1)
	{
		cache[i] = '\0';
		line[get_empty(line)] = ft_strdup(cache);
		aux = ft_strdup(cache + i + 1);
		free(cache);
		cache = aux;
		return (1);
	}
	buf[bytes_read] = '\0';
	aux = ft_strjoin(cache, buf);
	line[get_empty(line)] = ft_strdup(aux);
	return (0);
}