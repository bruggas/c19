/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:53:29 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/16 11:33:01 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (little[0] == '\0')
		return ((char *)big);
	while (*big && len > 0)
	{
		i = 0;
		while (little[i] && big[i] && little[i] == big[i] && len > 0)
		{
			i++;
			len--;
		}
		len += i;
		if (!little[i])
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
