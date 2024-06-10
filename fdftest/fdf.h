#ifndef FDF_H
# define FDF_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include <fcntl.h>
#include <math.h>
#ifndef WINDOW_HEIGHT
# define WINDOW_HEIGHT 1080
#endif
#ifndef WINDOW_WIDTH
# define WINDOW_WIDTH 1920
#endif
typedef struct {
        int x;
        int y;
	int color;
}       Point2D;

typedef	struct
{
	Point2D	point1;
	Point2D	point2;
	Point2D	point3;
	Point2D	point4;
}	Square;

typedef struct {
	double x;
	double y;
	double z;
}	Point3D;

typedef struct {
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;
	int r_step;
	int g_step;
	int b_step;
	int r;
	int g;
	int b;
}	Line_data;

typedef struct{
	char	***map;
	int	high_point;
	int	low_point;
	int	width;
	int	height;
	double	scale_x;
	double	scale_y;
	int	origin_x;
	int	origin_y;
        void    *img;
	void	*last_img;
        char    *addr;
        int             bits_per_pixel;
        int             line_length;
        int             endian;
	void	*mlx;
	void	*mlx_win;
	Point3D	rotation;
	Square	square;
}	t_terrain;
Point2D ft_projection(int x, int y, int z, t_terrain *terrain);
Point3D get_rotation(Point3D point, double angle_x, double angle_y, double angle_z);
int    read_terrain_map(t_terrain *terrain, char *map);
int get_color(int z, int high, int low);
int interpolate_color(int start_color, int end_color, float factor);
void get_color_steps(int color1, int color2, int length, Line_data *line);
int create_color(int red, int green, int blue);
void	end_window(t_terrain *terrain);
#endif
