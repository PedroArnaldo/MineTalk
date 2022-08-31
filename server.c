/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:46:57 by parnaldo          #+#    #+#             */
/*   Updated: 2022/08/31 11:59:39 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
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
*/
void handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	static char c = 0;
	static int i = 0;


	if(sig == SIGUSR1)
		c += (1 << (7 - i));
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

#include <stdio.h>
int main()
{
	struct sigaction sg;
	sg.sa_sigaction = handler;
	sg.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sg, NULL);
	sigaction(SIGUSR1, &sg, NULL);
	ft_printf("PID: %d\n", getpid());

	while(1)
	{
		pause();
	}
	return (0);
}
