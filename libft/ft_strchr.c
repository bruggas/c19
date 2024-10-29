/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:35:32 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/16 12:49:54 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*f;

	f = (char *)s;
	while (*f)
	{
		if (*f == (unsigned char)c)
			return (f);
		f++;
	}
	if ((unsigned char)c == '\0')
		return (f);
	return (NULL);
}
