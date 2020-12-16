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

void	update_cache(char **cache, char **line)
{
	char	*aux;
	char	*aux2;
	char	*n;

	aux = ft_strdup(*cache);
	//:printf("aux :%s\n", aux); 
	aux2 = ft_strdup(ft_strchr(*cache, '\n') + 1);
	*(ft_strchr(aux, '\n')) = 0;
	*line = ft_strdup(aux);
//	free(aux);
//	free(cache);
	*cache = aux2;
}

int	get_next_line(int fd, char **line)
{
	static char	*cache[4096];
	char		*buf;
	int			bytes_read;
	char		*aux;

	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!cache[fd])
		cache[fd] = ft_strdup("");
	if (!line || fd < 0 || BUFFER_SIZE <= 0 ||
			(bytes_read = read(fd, buf, 0)) < 0)
	{
		free(buf);
		return (-1);
	}
	printf("1\n");
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
	printf("2\n");
		buf[bytes_read] = '\0';
	printf("3\n");
		aux = ft_strjoin(cache[fd], buf);
	printf("4\n");
		free(cache[fd]);
	printf("5\n");
		cache[fd] = aux;
	printf("6\n");
		if (ft_strchr(cache[fd], '\n'))
		{
	printf("7\n");
//			printf("%s", ft_strchr(cache[fd], '\n'));
			break ;
		}
	printf("----------------------------------------------------8\n");
	printf("----------------------------------------------------8\n");
	printf("----------------------------------------------------8\n");
	printf("----------------------------------------------------8\n");
	printf("----------------------------------------------------8\n");
	}
	update_cache(&(cache[fd]), line);
	free(buf);
	if (ft_strlen(cache[fd]) > 0)
		return(1);
	return (0);
}
