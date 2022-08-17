/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:51:11 by parnaldo          #+#    #+#             */
/*   Updated: 2022/07/08 22:11:05 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printvar(const char c, va_list var)
{
	if (c == 'c')
		return (ft_putchar(va_arg(var, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(var, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_printfdec(va_arg(var, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(var, unsigned int)));
	else if (c == 'x')
		return (ft_printfhex(va_arg(var, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_printfhex(va_arg(var, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putstr("0x")
			+ ft_printfhex(va_arg(var, unsigned long), "0123456789abcdef"));
	else if (c == '%')
		return (ft_putchar(c));
	else if (c != '\0')
		return (ft_putchar(c));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_len;

	va_start(args, str);
	if (!str)
		return (0);
	i = 0;
	print_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_printvar(str[i + 1], args);
			i++;
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
