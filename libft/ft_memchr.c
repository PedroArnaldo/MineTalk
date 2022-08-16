/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:14:53 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/15 17:51:05 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux_src;

	while (n-- > 0)
	{
		aux_src = (unsigned char *) s;
		if (*aux_src == (unsigned char)c)
			return (aux_src);
		s++;
	}
	return (NULL);
}
