/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:43:41 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/23 17:05:37 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = 0;
	while (dest[len] && len < size)
			len++;
	index = len;
	while (src[len - index] && (len + 1) < size)
	{
		dest[len] = src[len - index];
		len++;
	}
	if (index < size)
		dest[len] = '\0';
	return (index + ft_strlen(src));
}
