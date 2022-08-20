/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:46:57 by parnaldo          #+#    #+#             */
/*   Updated: 2022/08/20 05:32:38 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int bits_to_char(int bits)
{
	int dec;
	int re;
	int base;

	base = 1;
	re = 1;
	dec = 0;
	while(bits > 0)
	{
		re = bits % 10;
		dec = dec + re * base;
		bits = bits / 10;
		base = base * 2;
	}
	return (dec);
}

void handler(int c)
{
	ft_printf("SIGUSR%d\n", c);
}

#include <stdio.h>
int main()
{
	struct sigaction sg;
	sg.sa_handler = handler;
	sigaction(SIGUSR2, &sg, NULL);
	sigaction(SIGUSR1, &sg, NULL);
	ft_printf("PID: %d\n", getpid());

	while(1)
	{
		sleep(1);
	}
	return (0);
}
