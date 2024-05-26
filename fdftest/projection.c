/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:43:04 by felix             #+#    #+#             */
/*   Updated: 2024/05/23 02:12:41 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	interpolate_color(int start_color, int end_color, float factor)
{
	int	r;
	int	g;
	int	b;

	r = ((start_color >> 16) & 0xFF) + (int)((((end_color >> 16) & 0xFF)
				- ((start_color >> 16) & 0xFF)) * factor);
	g = ((start_color >> 8) & 0xFF) + (int)((((end_color >> 8) & 0xFF)
				- ((start_color >> 8) & 0xFF)) * factor);
	b = (start_color & 0xFF) + (int)(((end_color & 0xFF) - (start_color & 0xFF))
			* factor);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(int z, int high, int low)
{
	int		dark_green;
	int		dark_blue;
	int		red;
	float	factor;

	dark_green = 0x28a700;
	dark_blue = 0x00008B;
	red = 0xa70000;
	if (z == 0)
		return (dark_green);
	else if (z < 0)
	{
		factor = (float)z / low;
		if (factor > 1)
			factor = 1;
		return (interpolate_color(dark_green, dark_blue, factor));
	}
	else
	{
		factor = (float)z / high;
		if (factor > 1)
			factor = 1;
		return (interpolate_color(dark_green, red, factor));
	}
}

Point3D	get_rotation(Point3D point, double angle_x, double angle_y,
		double angle_z)
{
	Point3D	rotated;
	double	rad_x;
	double	rad_y;
	double	rad_z;

	rad_x = (angle_x * M_PI / 180.0);
	rad_y = (angle_y * M_PI / 180.0);
	rad_z = (angle_z * M_PI / 180.0);
	rotated.y = point.y * cos(rad_x) - point.z * sin(rad_x);
	rotated.z = point.y * sin(rad_x) + point.z * cos(rad_x);
	point.y = rotated.y;
	point.z = rotated.z;
	rotated.x = point.x * cos(rad_y) + point.z * sin(rad_y);
	rotated.z = -point.x * sin(rad_y) + point.z * cos(rad_y);
	point.x = rotated.x;
	point.z = rotated.z;
	rotated.x = point.x * cos(rad_z) - point.y * sin(rad_z);
	rotated.y = point.x * sin(rad_z) + point.y * cos(rad_z);
	rotated.z = point.z;
	return (rotated);
}

Point2D	ft_projection(int x, int y, int z, t_terrain *terrain)
{
	Point3D	point;
	Point2D	projection;

	point.x = x * terrain->scale_x;
	point.y = y * terrain->scale_x;
	point.z = z;
	point = get_rotation(point, terrain->rotation.x,
			terrain->rotation.y, terrain->rotation.z);
	projection.x = (int)point.x + terrain->origin_x;
	projection.y = (int)point.y + terrain->origin_y;
	projection.color = get_color(z, terrain->high_point, terrain->low_point);
	return (projection);
}
