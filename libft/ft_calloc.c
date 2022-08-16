/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:21:30 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/15 18:17:09 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_m;
	void	*ptr;

	total_m = nmemb * size;
	ptr = malloc(total_m);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_m);
	return (ptr);
}
