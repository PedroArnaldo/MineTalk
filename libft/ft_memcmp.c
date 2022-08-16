/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:56:06 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/20 10:40:36 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			index;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	index = 0;
	while (index < n)
	{
		if (str1[index] != str2[index])
			return ((int)(str1[index] - str2[index]));
		index++;
	}
	return (0);
}
