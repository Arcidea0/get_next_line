/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:03:25 by armgevor          #+#    #+#             */
/*   Updated: 2023/04/30 12:00:16 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX 65536

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *stat, char *buffer);
char	*ft_strchr(const char *buffer, int ch);
int		ft_strlen(const char *s);
char	*kardacox(char *tox, int fd, char *buf);
char	*skizb(char *str);
char	*verj(char *str);
void	ffree(char *str);

#endif