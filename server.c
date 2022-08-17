/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:46:57 by parnaldo          #+#    #+#             */
/*   Updated: 2022/08/17 15:10:16 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int bits_to_char(int bits)
{
	int dec;
	int rem;
	int base;

	base = 1;
	rem = 1;
	dec = 0;
	while(bits > 0)
	{
		rem = bits % 10;
		dec = dec + rem * base;
		bits = bits / 10;
		base = base * 2;
	}
	return (dec);
}

void handler()
{
	write(STDOUT_FILENO, "Closed Process!\n", 16);
}

#include <stdio.h>
int main()
{
	signal(SIGINT, handler);
	ft_printf("PID: %d\n", getpid());

	ft_printf("%c\n", bits_to_char(1100001));
	return (0);
}
