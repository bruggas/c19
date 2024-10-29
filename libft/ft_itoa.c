/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:03:04 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/16 12:42:20 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;
	int	sign;

	sign = 0;
	len = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len + sign);
}

static void	fill(char *d, int n, int start, int len)
{
	if (n == 0)
	{
		d[0] = '0';
		d[1] = '\0';
		return ;
	}
	if (n < 0)
		n = -n;
	d[len + 1] = '\0';
	while (len >= start)
	{
		d[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*d;

	len = get_len(n);
	d = (char *)malloc(len + 1);
	if (!d)
		return (NULL);
	if (n == -2147483648)
	{
		d[0] = '-';
		d[1] = '2';
		fill(d, 147483648, 2, len - 1);
	}
	else if (n < 0)
	{
		d[0] = '-';
		fill(d, n, 1, len - 1);
	}
	else
		fill(d, n, 0, len - 1);
	return (d);
}
