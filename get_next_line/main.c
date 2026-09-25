/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kasen <kasen@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/25 11:23:53 by kasen            #+#    #+#              */
/*   Updated: 2026/09/25 15:15:06 by kasen           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*b;
	int		fd = open("hello.txt", O_RDWR, 0777);

	while ((b = get_next_line_bonus(fd)) != NULL)
	{
		printf("%s", b);
		free(b);
	}
}
