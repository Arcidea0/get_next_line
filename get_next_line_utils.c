/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:12:34 by armgevor          #+#    #+#             */
/*   Updated: 2023/04/30 11:48:16 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ffree(char *str)
{
	free(str);
	str = NULL;
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char	*ft_strchr(const char *buffer, int ch)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == ch)
			return ((char *)buffer + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *stat, char *buffer)
{
	char	*join;
	size_t	i;
	size_t	c;

	if (!stat)
	{
		stat = (char *)malloc(sizeof(char) * 1);
		stat[0] = '\0';
	}
	if (!stat || !buffer)
		return (NULL);
	i = -1;
	c = -1;
	join = (char *)malloc(sizeof(char)
			* (ft_strlen(stat) + ft_strlen(buffer) + 1));
	if (!join)
		return (NULL);
	while (stat[++i] != '\0')
		join[i] = stat[i];
	while (buffer[++c])
		join[i++] = buffer[c];
	join[i] = '\0';
	free(stat);
	return (join);
}
