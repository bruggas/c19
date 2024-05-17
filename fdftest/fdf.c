/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:50:30 by felix             #+#    #+#             */
/*   Updated: 2024/05/17 01:16:11 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#define SCALE_X 10
#define SCALE_Y 10

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = x1 < x2 ? 1 : -1;
	sy = y1 < y2 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		my_pixel_put(data, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	draw_triangle(t_data *data, Point2D point1, Point2D point2, Point2D point3, Point2D point4, int color)
{
	draw_line(data, point1.x, point1.y, point2.x, point2.y, 0x00FFFFFF);
	draw_line(data, point2.x, point2.y, point3.x, point3.y, 0x00FFFFFF);
	draw_line(data, point3.x, point3.y, point1.x, point1.y, 0x00FFFFFF);
	draw_line(data, point2.x, point2.y, point4.x, point4.y, 0x00FFFFFF);
	draw_line(data, point4.x, point4.y, point3.x, point3.y, 0x00FFFFFF);
}

void	render_terrain(t_data *data, int fd)
{
	int	x;
	int	y;
	char	*col;
	char	*col_next;
	Point2D	point1;
	Point2D	point2;
	Point2D	point3;
	Point2D	point4;

	col = NULL;
	y = 0;
	while ((col_next = get_next_line(fd)))
	{
		if (y == 0)
		{
			col = col_next;
			col_next = get_next_line(fd);
		}
		x = 0;
		while (col[x + 2])
		{
			point1 = ft_projection(x, y, col[x], SCALE_X, SCALE_Y);
			point2 = ft_projection(x, y + 1, col_next[x], SCALE_X, SCALE_Y);
			point3 = ft_projection(x + 2, y, col[x + 2], SCALE_X, SCALE_Y);
			point4 = ft_projection(x + 2, y + 1, col_next[x + 2], SCALE_X, SCALE_Y);
			draw_triangle(data, point1, point2, point3, point4, 0x00FFFFFF);
			x += 2;
		}
		col = col_next;
		y++;
	}
	free(col);
	free(col_next);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	fd;

	fd = open("42.fdf", O_RDONLY);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	render_terrain(&img, fd);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

