/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 08:32:10 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/18 15:01:36 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_num(int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
		size++;
	n = n / 10;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*cal_itoa(int n)
{
	size_t			size;
	char			*str;
	unsigned int	sin;

	sin = 0;
	size = size_num(n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		sin = 1;
		n = n * -1;
	}
	str[size] = '\0';
	while (size)
	{
		size--;
		str[size] = (n % 10) + 48;
		n = n / 10;
	}
	if (sin)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (cal_itoa(n));
}
