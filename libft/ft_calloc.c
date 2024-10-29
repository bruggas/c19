/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:28:58 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/15 13:30:26 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*d;

	d = malloc(nmemb * size);
	if (!d)
		return (NULL);
	ft_bzero(d, nmemb * size);
	return (d);
}
