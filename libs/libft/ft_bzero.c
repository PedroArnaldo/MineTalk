/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:22:24 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/20 10:32:45 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*clean;
	size_t			index;

	clean = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		clean[index] = 0;
		index++;
	}
}
