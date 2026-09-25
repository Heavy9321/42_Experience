/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 11:01:30 by kasen             #+#    #+#             */
/*   Updated: 2026/09/25 14:26:56 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_first(int fd, char *s1)
{
	char	*buffer;
	ssize_t	i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (!gnl_bonus_strchr(s1, '\n') && (i > 0))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		s1 = gnl_bonus_strjoin(s1, buffer);
	}
	free(buffer);
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
		return (NULL);
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
	alloc = malloc(gnl_bonus_strlen(s2) - i + 1);
	if (!s2[i] || !alloc)
	{
		free(s2);
		return (NULL);
	}
	i++;
	j = 0;
	while (s2[i])
		alloc[j++] = s2[i++];
	alloc[j] = '\0';
	free(s2);
	return (alloc);
}

char	*get_next_line_bonus(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_first(fd, stash);
	if (!stash[fd])
		return (NULL);
	line = get_line(*stash);
	stash[fd] = clean_stash(*stash);
	return (line);
}
