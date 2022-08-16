/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:34:18 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/20 10:34:00 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*aux_dst;
	char	*aux_src;

	aux_dst = (char *) dst;
	aux_src = (char *) src;
	if (aux_src < aux_dst)
	{
		while (len--)
		{
			aux_dst[len] = aux_src[len];
		}
		return (aux_dst);
	}
	ft_memcpy(aux_dst, aux_src, len);
	return (aux_dst);
}
