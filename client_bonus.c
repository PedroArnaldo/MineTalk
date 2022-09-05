/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:26:43 by parnaldo          #+#    #+#             */
/*   Updated: 2022/09/05 13:26:45 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	char_to_bits(unsigned char c, pid_t pid)
{
	int	count;

	count = 8;
	while (count-- > 0)
	{
		if (!(c & 128))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c << 1;
		usleep(250);
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("end.");
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	pid_t	pid;

	signal(SIGUSR2, handler);
	pid = ft_atoi(argv[1]);
	i = 0;
	if (argc != 3)
		ft_printf("Error %s", argv[2]);
	else
	{
		while (argv[2][i])
		{
			char_to_bits(argv[2][i], pid);
			i++;
		}
		char_to_bits(3, pid);
	}
}
