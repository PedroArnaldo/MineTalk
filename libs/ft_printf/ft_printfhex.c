/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:35:21 by parnaldo          #+#    #+#             */
/*   Updated: 2022/07/07 02:51:24 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	size_num(unsigned long n)
{
	size_t	size;

	size = 0;
	while (n)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char	*ft_convert_to_hex(unsigned long n, char *base)
{
	size_t			size;
	char			*str;

	size = size_num(n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	while (size--)
	{
		str[size] = base[n % 16];
		n = n / 16;
	}
	return (str);
}

int	ft_printfhex(unsigned long n, char *base)
{
	unsigned long	print_len;
	char			*str;

	print_len = 0;
	if (n == 0)
		print_len += write(1, "0", 1);
	else
	{
		str = ft_convert_to_hex(n, base);
		print_len += ft_putstr(str);
		free(str);
	}
	return (print_len);
}
