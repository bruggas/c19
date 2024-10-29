/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:45:48 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/15 14:25:13 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	size;

	size = ft_strlen(s);
	d = (char *)malloc(size + 1);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, size + 1);
	return (d);
}
