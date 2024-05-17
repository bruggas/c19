/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:44:44 by fdaems            #+#    #+#             */
/*   Updated: 2024/05/16 15:49:52 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
float	*matmul(float x, float y, float z){
	float	point[3][1] = {
		{x},
		{y},
		{z}
	};
	float	projection[2][3] = {
		{1, 0, 0},
		{0, 1, 0}
	};
	int		i;
	int		j;
	int		k;
	float	sum;
	float	*result;


	i = 0;
	result = malloc(2 *sizeof(float) + 1);
	while (i < 2)
	{
		j = 0;
		sum = 0;
		k = 0;
		while (k < 3)
		{
			sum += projection[i][k] * point[k][0];
			k++;
		}
		result[i] += sum;
		i++;
	}
	return (result);
}

int	main()
{
	float *r;
	r = matmul(100,75,50);
	printf("%f, %f", r[0], r[1]);
}
