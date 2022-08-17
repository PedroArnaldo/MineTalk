/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:14:51 by parnaldo          #+#    #+#             */
/*   Updated: 2022/06/22 20:04:53 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	n_words;

	i = 0;
	n_words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			n_words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n_words);
}

static size_t	count_latter(size_t i, char *str, char c)
{
	size_t	count;

	count = 0;
	while (str[i] != c && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_split_word(char const *s, char c, size_t n_words, char **m_str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < n_words && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			m_str[j] = ft_substr((char *)s, i, count_latter(i, (char *)s, c));
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	m_str[j] = NULL;
	return (m_str);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	char	**ptr;

	if (s == NULL)
		return (0);
	n_words = count_words(s, c);
	ptr = (char **) ft_calloc(sizeof(char *), n_words + 1);
	if (ptr == NULL)
		return (NULL);
	return (ft_split_word(s, c, n_words, ptr));
}
