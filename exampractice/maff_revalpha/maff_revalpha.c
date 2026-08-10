/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:20:23 by kaansen           #+#    #+#             */
/*   Updated: 2026/07/03 12:23:25 by kaansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(void)
{
	char upper;
	char lower;

	upper = 'Y';
	lower = 'z';
	while(upper >= 'A')
	{
		write(1, &lower, 1);
		write(1, &upper, 1);

		lower -= 2;
		upper -= 2;
	}
	write(1, "\n", 1);
	return(0);
}
