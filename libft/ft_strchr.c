/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:37:00 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/21 13:42:41 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*dst_str;

	dst_str = (char *) str;
	while (*dst_str)
	{
		if (*dst_str == (char)c)
			return ((char *) dst_str);
		dst_str++;
	}
	if (*dst_str == (char)c)
		return ((char *) dst_str);
	return (NULL);
}
