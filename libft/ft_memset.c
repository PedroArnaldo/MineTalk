/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:28:08 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/20 10:32:15 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			count;
	unsigned char	*ptr;

	ptr = (unsigned char *) dest;
	count = 0;
	while (count < n)
	{
		ptr[count] = c;
		count++;
	}
	return (dest);
}
