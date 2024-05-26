/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:50:30 by felix             #+#    #+#             */
/*   Updated: 2024/05/23 17:25:49 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <stdio.h>

void	my_pixel_put(t_terrain *terrain, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = terrain->addr + (y * terrain->line_length + x
				* (terrain->bits_per_pixel / 8));
		*(unsigned int*) dst = color;
	}
}

void	clear_window(t_terrain *terrain)
{
	int	y;
	int	x;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_pixel_put(terrain, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

Line_data	calc_line(int x1, int y1, int x2, int y2)
{
	Line_data	line;
	line.dx = abs(x2 - x1);
	line.dy = abs(y2 - y1);
	line.sx = x1 < x2 ? 1 : -1;
	line.sy = y1 < y2 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	line.r_step = 0;
	line.g_step = 0;
	line.b_step = 0;
	line.r = 0;
	line.g = 0;
	line.b = 0;
	return (line);
}

void	draw_line(t_terrain *terrain, Point2D point1, Point2D point2)
{
	int			len;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			color;
	Line_data	line;

	x1 = point1.x;
	y1 = point1.y;
	x2 = point2.x;
	y2 = point2.y;
	line = calc_line(x1, y1, x2, y2);
	len = sqrt(line.dx * line.dx + line.dy * line.dy);
	if (len == 0)
	{
		my_pixel_put(terrain, x1, y1, point1.color);
		return ;
	}
	get_color_steps(point1.color, point2.color, len, &line);
	while (1)
	{
		color = create_color(line.r, line.g, line.b);
		my_pixel_put(terrain, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			x1 += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			y1 += line.sy;
		}
		line.r += line.r_step;
		line.g += line.g_step;
		line.b += line.b_step;
	}
}

void	draw_square(t_terrain *terrain, Square square)
{
	draw_line(terrain, square.point1, square.point2);
	draw_line(terrain, square.point2, square.point3);
	draw_line(terrain, square.point3, square.point4);
	draw_line(terrain, square.point4, square.point1);
}

void	get_square(int x, int y, t_terrain *terrain, Square *square)
{
		Point2D	point1;
		Point2D	point2;
		Point2D	point3;
		Point2D	point4;

		point1 = ft_projection(x, y, ft_atoi(terrain->map[y][x]), terrain);
		point2 = ft_projection(x, y + 1, ft_atoi(terrain->map[y + 1][x]), terrain);
		point3 = ft_projection(x + 1, y + 1, ft_atoi(terrain->map[y + 1][x + 1]), terrain);
		point4 = ft_projection(x + 1, y, ft_atoi(terrain->map[y][x + 1]), terrain);
		square->point1 = point1;
		square->point2 = point2;
		square->point3 = point3;
		square->point4 = point4;
}

void	render_terrain(t_terrain *terrain)
{
		int	x;
		int	y;
		Square	square;

	y = 0;
	while (terrain->map[y] && terrain->map[y + 1])
	{
		x = 0;
		while (terrain->map[y + 1][x + 1])
		{
				get_square(x, y, terrain, &square);
				draw_square(terrain, square);
				x++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_terrain *terrain)
{
    int redraw = 0;

    if (keycode == 101) {
	terrain->scale_x += 0.8;
	terrain->scale_y += 0.4;
	redraw = 1;
    } else if (keycode == 97 && terrain->scale_x - 0.8 > 0 && terrain->scale_y - 0.4 > 0) {
	terrain->scale_x -= 0.8;
	terrain->scale_y -= 0.4;
	redraw = 1;
    }else if (keycode == 113) {
	terrain->origin_x -= 10;
	redraw = 1;
    } else if (keycode == 100) {
	terrain->origin_x += 10;
	redraw = 1;
    } else if (keycode == 115) {
	terrain->origin_y -= 10;
	redraw = 1;
    } else if (keycode == 119) {
	terrain->origin_y += 10;
	redraw = 1;
    } else if (keycode == 65363) {
	terrain->rotation.y += 5;
	redraw = 1;
    } else if (keycode == 65361) {
	terrain->rotation.y -= 5;
	redraw = 1;
    }else if (keycode == 65362) {
	terrain->rotation.x += 5;
	redraw = 1;
    }else if (keycode == 65364) {
	terrain->rotation.x -= 5;
	redraw = 1;
    }

    if (redraw) {
	clear_window(terrain);
	render_terrain(terrain);
	mlx_put_image_to_window(terrain->mlx, terrain->mlx_win, terrain->img, 0, 0);
    }
	return (0);
}

int	main(void)
{
	t_terrain	terrain;
	Point3D		rotation;
	char	*map;

	map = "../maps/42.fdf";
	rotation.x = 30;
	rotation.y = 30;
	rotation.z = 0;
	terrain.origin_x = 0;
	terrain.origin_y = 0;
	terrain.low_point = 0;
	terrain.high_point = 0;
	terrain.rotation = rotation;
	terrain.mlx = mlx_init();
	terrain.mlx_win = mlx_new_window(terrain.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	terrain.img = mlx_new_image(terrain.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	terrain.addr = mlx_get_data_addr(terrain.img, &terrain.bits_per_pixel, &terrain.line_length, &terrain.endian);
	if (read_terrain_map(&terrain, map) != 0)
		return (0);
	terrain.scale_x = WINDOW_WIDTH / (terrain.width + 50);
	terrain.scale_y = WINDOW_HEIGHT / (terrain.height + 25);
	render_terrain(&terrain);
	mlx_put_image_to_window(terrain.mlx, terrain.mlx_win, terrain.img, 0, 0);
	mlx_key_hook(terrain.mlx_win, key_hook, &terrain);
	mlx_loop(terrain.mlx);
}
