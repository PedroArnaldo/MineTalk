/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:26:12 by parnaldo          #+#    #+#             */
/*   Updated: 2022/09/05 13:26:14 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c = 0;
	static int	i = 0;

	(void)ucontext;
	if (sig == SIGUSR1)
		c += (1 << (7 - i));
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == 3)
			kill(info->si_pid, SIGUSR2);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sg;

	sg.sa_sigaction = handler;
	sg.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sg, NULL);
	sigaction(SIGUSR1, &sg, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
