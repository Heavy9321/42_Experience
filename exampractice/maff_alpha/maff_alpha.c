/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:13:25 by kaansen           #+#    #+#             */
/*   Updated: 2026/07/03 12:19:09 by kaansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(void)
{
	char	upper;
	char	down;

	upper = 'B';
	down = 'a';
	while(upper <= 'Z')
	{
		write(1, &down, 1);
		write(1, &upper, 1);
		down += 2;
		upper += 2;
	}
	write(1, "\n", 1);
	return(0);
}
