#ifndef FDF_H
# define FDF_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include <fcntl.h>
typedef struct {
        int x;
        int y;
}       Point2D;

typedef struct  s_data {
        void    *img;
        char    *addr;
        int             bits_per_pixel;
        int             line_length;
        int             endian;
}                               t_data;

Point2D ft_projection(int x, int y, int z, float scaleX, float scaleY);
#endif
