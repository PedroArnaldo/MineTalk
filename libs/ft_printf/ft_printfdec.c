/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:20:10 by parnaldo          #+#    #+#             */
/*   Updated: 2022/07/07 02:49:45 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*ft_itoa(int n)
{
	size_t			size;
	char			*str;
	int				sin;
	long int		i;

	i = n;
	sin = 0;
	size = size_num(n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	if (i < 0)
	{
		sin = 1;
		i = i * -1;
	}
	str[size] = '\0';
	while (size--)
	{
		str[size] = (i % 10) + 48;
		i = i / 10;
	}
	if (sin)
		str[0] = '-';
	return (str);
}

size_t	ft_printfdec(int n)
{
	size_t	printf_len;
	char	*num;

	printf_len = 0;
	if (n == 0)
		printf_len += ft_putchar('0');
	else
	{
		num = ft_itoa(n);
		printf_len += ft_putstr(num);
		free(num);
	}
	return (printf_len);
}
