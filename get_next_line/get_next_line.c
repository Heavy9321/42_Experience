/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 19:05:59 by kasen             #+#    #+#             */
/*   Updated: 2026/09/27 14:40:55 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_first(int fd, char *s1)
{
	char	*buffer;
	char	*tmp;
	ssize_t	i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), free(s1), NULL);
	i = 1;
	while (!gnl_strchr(s1, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(buffer), free(s1), NULL);
		if (i == 0)
			break ;
		buffer[i] = '\0';
		tmp = gnl_strjoin(s1, buffer);
		free(s1);
		s1 = tmp;
	}
	free(buffer);
	if (!s1 || !s1[0])
		return (free(s1), NULL);
	return (s1);
}

char	*get_line(char *s1)
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
		return (free(s1), NULL);
	line[i] = '\0';
	while (--i >= 0)
		line[i] = s1[i];
	return (line);
}

char	*clean_stash(char *s2)
{
	int		i;
	int		j;
	char	*alloc;

	i = 0;
	if (!s2 || !s2[0])
		return (NULL);
	while (s2[i] && s2[i] != '\n')
		i++;
	if (!s2[i])
		return (free(s2), NULL);
	alloc = malloc(gnl_strlen(s2) - i + 1);
	if (!alloc)
		return (free(s2), NULL);
	i++;
	j = 0;
	while (s2[i])
		alloc[j++] = s2[i++];
	alloc[j] = '\0';
	free(s2);
	return (alloc);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_first(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = clean_stash(stash);
	return (line);
}
