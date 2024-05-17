/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:43:04 by felix             #+#    #+#             */
/*   Updated: 2024/05/17 01:04:50 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
Point2D	ft_projection(int x, int y, int z, float scaleX, float scaleY)
{
	Point2D	point;
	point.x = (int)(((x - y) * scaleX) + 1920 / 2);
	point.y = (int)(((x + y) * scaleY - z) + 1080 / 2);
	return (point);
}
