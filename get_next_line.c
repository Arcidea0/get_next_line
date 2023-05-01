/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:03:25 by armgevor          #+#    #+#             */
/*   Updated: 2023/04/30 11:58:02 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*set;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	stat = kardacox(stat, fd, buf);
	if (!stat)
		stat = NULL;
	set = skizb(stat);
	stat = verj(stat);
	if (stat && !stat[0])
	{
		free(stat);
		stat = NULL;
	}
	return (set);
}

char	*kardacox(char *tox, int fd, char *buf)
{
	char		*set;
	int			i;

	set = NULL;
	if (tox)
		set = ft_strjoin(set, tox);
	i = 1;
	while (i != 0 && !ft_strchr(set, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buf[i] = '\0';
		set = ft_strjoin(set, buf);
	}
	free(tox);
	return (set);
}

char	*skizb(char *str)
{
	size_t		i;
	char		*ptr;

	i = 0;
	if (!str[0])
		return (0);
	if (str)
		while (str[i] && str[i] != '\n')
			i++;
	ptr = malloc(sizeof(char) * (i + 2));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*verj(char *str)
{
	int		i;
	int		j;
	char	*a;

	i = 0;
	j = 0;
	if (str)
		while (str[i] && str[i] != '\n')
			i++;
	else if (!str[i] || !str)
		ffree(str);
	a = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!a)
		return (NULL);
	if (str[i])
		while (str[++i])
			a[j++] = str[i];
	a[j] = '\0';
	free(str);
	return (a);
}
