/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 19:05:59 by kasen             #+#    #+#             */
/*   Updated: 2026/09/17 04:36:45 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_first(int fd, char *s1)
{
	char	*buffer;
	ssize_t	i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (!gnl_strchr(s1, '\n') && (i > 0))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		s1 = gnl_strjoin(s1, buffer);
	}
	free(buffer);
	return (s1);
}

char	*second_string(char *s1)
{
	int		i;
	char	*line;

	if (!s1 || !s1[0])
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i-- >= 0)
		line[i] = s1[i];
	return (line);
}

char	*clean_stash(void)
{
}

char	*get_next_line(int fd)
{
}
