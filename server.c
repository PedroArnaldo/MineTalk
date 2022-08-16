/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:46:57 by parnaldo          #+#    #+#             */
/*   Updated: 2022/08/16 13:35:49 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler()
{
	write(STDOUT_FILENO, "Closed Process!\n", 16);
}

#include <stdio.h>
int main()
{
	signal(SIGINT, handler);
	ft_printf("PID: %d\n", getpid());
	return (0);
}
