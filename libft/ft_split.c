/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:18:16 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/16 12:11:22 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	word_count(char const *s, char c)
{
	unsigned int	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static int	error(char **d, size_t words)
{
	while (words > 0)
	{
		free(*d);
		d--;
		words--;
	}
	return (0);
}

static int	word_make(char **d, char const *str, char c, size_t words)
{
	size_t	len;

	while (*str)
	{
		len = 0;
		while (*str == c)
			str++;
		while (str[len] != c && str[len])
			len++;
		*d = ft_substr(str, 0, len);
		if (!*d)
			return (error(d, words));
		if (*str && len != 0)
			d++;
		str += len;
	}
	*d = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**d;
	unsigned int	words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	d = (char **)malloc((words + 1) * sizeof(char *));
	if (!d)
		return (NULL);
	if (word_make(d, s, c, words) != 1)
	{
		free(d);
		return (NULL);
	}
	return (d);
}
