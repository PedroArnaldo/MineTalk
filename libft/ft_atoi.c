/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:37:56 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/22 19:46:18 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c == '\t'
			|| c == '\v'
			|| c == '\r'
			|| c == '\n'
			|| c == '\f'
			|| c == ' '))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sin;
	int	result;
	int	i;

	i = 0;
	sin = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sin = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sin);
}
