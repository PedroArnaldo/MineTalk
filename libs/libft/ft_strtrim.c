/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:54:43 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/21 19:02:16 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		size_end;
	int		i;
	char	*s2;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = (char *) s1;
	start = 0;
	while (s1[start] && ft_strchr(set, str[start]))
		start++;
	size_end = ft_strlen(str);
	while (size_end > start && ft_strchr(set, str[size_end - 1]))
		size_end--;
	s2 = (char *) malloc(sizeof(char) * (size_end - start + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (start < size_end)
		s2[i++] = str[start++];
	s2[i] = '\0';
	return (s2);
}
