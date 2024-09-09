#ifndef FRACTOL_H
# define FRACTOL_H

# include "my_lib/my_lib.h"
# include "minilibX/mlx.h"

# include <math.h>
# include <stdlib.h>

// ADJUSTABLES
# define COLOR_CODE 0x0000CD
# define WIDTH 600
# define HEIGHT 500
# define MAX_ITERATIONS 80

// KEYCODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractol;

// compute.c
void	compute_mandelbrot(t_fractol *fractol);
void	compute_julia(t_fractol *fractol);

// draw.c
int		draw_fractol(t_fractol *fractol, char *input);
void	*draw_mandelbrot(void *fractol_void);
void	draw_julia(t_fractol *fractol);
void	draw_first_fractol(t_fractol *fractol, int argc, char **argv);
void	draw_first_julia(t_fractol *fractol, int argc, char **argv);

// events.c
void	zoom(t_fractol *fractol, int x, int y, int zoom);
int		key_hook(int key_code, t_fractol *fractol);
int		mouse_hook(int mouse_code, int x, int y, t_fractol *fractol);

// inits.c
void	init_fractol(t_fractol *fractol);
void	init_mlx(t_fractol *fractol);

// main.c
int		main(int argc, char **argv);

//tools.c
void	color_pixel(t_fractol *fractol, int x, int y, int color);
int		clean_exit(t_fractol *fractol);
double	ft_atod(char *s);

#endif
