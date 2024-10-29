/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:03:17 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/15 13:36:38 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*d;
	char const	*src;
	size_t		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	src = s;
	src += start;
	if (len > ft_strlen(src))
		len = ft_strlen(src);
	d = (char *)malloc(len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = src[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
