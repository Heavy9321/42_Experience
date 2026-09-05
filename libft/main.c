/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:40:19 by kasen             #+#    #+#             */
/*   Updated: 2026/09/03 17:37:36 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "string.h"
#include "libft.h"

void	print_content(void *content)
{
	printf("%s\n", (char *) content);
}

void	del(void *content)
{
	free(content);
}

void	*printmm(void *content)
{
	char	*old = (char *) content;
	char	*new = ft_strdup(old);
	int		i = 0;

	while (new[i])
	{
		if (new[i] >= 'a' && new[i] <= 'z')
			new[i] -= 32;
		i++;
	}
	return (new);
}

int	main(void)
{
	char	**arr = ft_split(" hello he. hello.  ", ' ');
	t_list	*head;
	t_list	*n1 = ft_lstnew(ft_strdup(arr[0]));
	t_list	*n2 = ft_lstnew(ft_strdup(arr[1]));
	t_list	*n3 = ft_lstnew(ft_strdup(arr[2]));

	head = NULL;
	ft_lstadd_back(&head, n1);
	ft_lstadd_back(&head, n2);
	ft_lstadd_back(&head, n3);
	ft_lstiter(head, print_content);
	t_list	*map;

	map = ft_lstmap(head, printmm, del);
	ft_lstiter(map, print_content);
	ft_lstclear(&head, del);
	ft_lstclear(&map, del);
}
