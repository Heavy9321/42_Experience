/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 19:02:45 by kasen             #+#    #+#             */
/*   Updated: 2026/09/16 20:35:47 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strchr(const char *s, int c);

#endif
