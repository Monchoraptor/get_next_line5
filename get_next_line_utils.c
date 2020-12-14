/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:02:25 by amoracho          #+#    #+#             */
/*   Updated: 2020/12/13 18:02:42 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*p;

	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	p = malloc(i + 1);
	if (p == 0)
		return (0);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(p + i) = *(s1 + i);
		i++;
	}
	*(p + i) = 0;
	return (p);
}
char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*aux;

	i = 0;
	j = 0;
	aux = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!aux)
		return (0);
	while (s1[i])
	{
		aux[i] = s1[i];
		i++;
	}
	while (s2[j])
		aux[i++] = s2[j++];
	aux[i] = '\0';
	return (aux);
}