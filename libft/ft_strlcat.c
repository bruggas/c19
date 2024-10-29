/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:14:27 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/16 12:52:59 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest,	const char *src, size_t size)
{
	size_t	i;
	size_t	y;
	char	*s;

	s = (char *)src;
	i = ft_strlen(dest);
	y = 0;
	if (size < i || size == 0)
		return (ft_strlen(s) + size);
	while (i + y < size - 1 && s[y])
	{
		dest[i + y] = s[y];
		y++;
	}
	dest[i + y] = '\0';
	return (i + ft_strlen(s));
}
