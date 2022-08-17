/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:30:17 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/20 10:59:10 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*dst;
	char	*dst_start;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	dst = (char *) malloc(sizeof(char) * size);
	if (!dst)
		return (NULL);
	dst_start = dst;
	while (*s1)
		*dst++ = *s1++;
	while (*s2)
		*dst++ = *s2++;
	*dst = '\0';
	return (dst_start);
}
