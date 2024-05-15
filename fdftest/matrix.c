/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:44:44 by fdaems            #+#    #+#             */
/*   Updated: 2024/05/15 17:26:45 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	projection[2][3] = {
	{1, 0, 0},
	{0, 1, 1}
};

float	point[3][1] = {
	{100},
	{75},
	{50}
};

float	**matmul(float **a, float **b){
	float	result[2][1];
	int		i;
	int		j;
	int		k;
	float	sum;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 3)
		{
			sum = 0;
			k = 0;
			while (k < 1)
				sum += a[i][k] * b[k][j];
			result[i][j] = sum;
		}
	}
}
