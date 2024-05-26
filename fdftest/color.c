/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:49:55 by felix             #+#    #+#             */
/*   Updated: 2024/05/23 15:46:05 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static inline int	get_red(int color)
{
	return ((color >> 16) & 0xFF);
}

static inline int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

static inline int	get_blue(int color)
{
	return (color & 0xFF);
}

int	create_color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

void	get_color_steps(int color1, int color2, int length, Line_data *line)
{
	int	r2;
	int	g2;
	int	b2;

	line->r = get_red(color1);
	line->g = get_green(color1);
	line->b = get_blue(color1);
	r2 = get_red(color2);
	g2 = get_green(color2);
	b2 = get_blue(color2);
	line->r_step = (r2 - line->r) / length;
	line->g_step = (g2 - line->g) / length;
	line->b_step = (b2 - line->b) / length;
}
