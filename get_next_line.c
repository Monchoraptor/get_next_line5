/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:49 by amoracho          #+#    #+#             */
/*   Updated: 2020/12/14 21:50:18 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_empty(char **line)
{
	int i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}

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
//	printf("\n###\n%s\n###\n",s);
	while (*(s + i) != '\0')
	{
		if (s[i++] == '\n')
			return (i - 1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*cache;
	char		buf[BUFFER_SIZE + 1];
//	int			i;
//	char		*aux;
	int			bytes_read;

	if (!cache)
		cache = ft_strdup("");
//	printf("\n===\n%s\n===\n",cache);
	if (!line || fd < 0 || BUFFER_SIZE <= 0 ||
			(bytes_read = read(fd, buf, 0)) < 0)
	{
		free(buf);
		return (-1);
	}
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) == BUFFER_SIZE)
//			&& is_backslash_n(cache) != 0 && ft_strlen(cache))
	{
		buf[bytes_read] = '\0';
//		printf("\n@@@\n%s\n@@@\n", buf);
		cache = ft_strjoin(cache, buf);	
	}
		buf[bytes_read] = '\0';
	cache = ft_strjoin(cache, buf);	
//	printf("\n@1@@\n%i\n@@@\n", bytes_read);
//	printf("\n@2@@\n%i\n@@@\n", is_backslash_n(cache));
//	printf("\n@3@@\n%i\n@@@\n", ft_strlen(cache));
	if (is_backslash_n(cache) == 0)
	{
		*line = ft_strdup(cache);
		return (0);
	}
	if (is_backslash_n(cache) != 0)
	{
	*line = ft_substr(cache, 0, count_line(cache));
	cache =ft_substr(cache, count_line(cache) + 1, ft_strlen(cache));
	printf("\n---\n%s\n---\n",*line);
	}
	if (is_backslash_n(cache) == 0)
		*line = ft_strdup(cache);
		return (0);
	return (1);	
}
