/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_bonus.h                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kasen <kasen@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/25 11:00:51 by kasen            #+#    #+#              */
/*   Updated: 2026/09/25 15:15:01 by kasen           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line_bonus(int fd);
char	*gnl_bonus_strjoin(char const *s1, char const *s2);
size_t	gnl_bonus_strlen(const char *s);
char	*gnl_bonus_strchr(const char *s, int c);
char	*gnl_bonus_strdup(const char *s1);
void	*gnl_bonus_memcpy(void *dst, const void *src, size_t n);

#endif
