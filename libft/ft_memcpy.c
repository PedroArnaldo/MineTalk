/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:56:03 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/20 10:33:17 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;
	char	*aux_dst;
	char	*aux_src;

	if (src == NULL && dst == NULL)
		return (dst);
	aux_dst = (char *) dst;
	aux_src = (char *) src;
	index = 0;
	while (index < n)
	{
		aux_dst[index] = aux_src[index];
		index++;
	}
	return (aux_dst);
}
