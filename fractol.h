
#ifndef FRACTOL_H
# define FRACTOL_H

# include "my_lib/my_lib.h"
# include "minilibX/mlx.h"

# include <math.h>
# include <stdlib.h>
# include <X11/X.h>

// ADJUSTABLES
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 20

// Colours
#define BLACK           0x000000
#define WHITE           0xFFFFFF
#define RED             0xFF0000
#define GREEN           0x00FF00
#define BLUE            0x0000FF
#define YELLOW          0xFFFF00
#define CYAN            0x00FFFF
#define MAGENTA         0xFF00FF
#define ORANGE          0xFFA500
#define PURPLE          0x800080
#define PINK            0xFFC0CB
#define BROWN           0xA52A2A
#define LIME            0x00FF00
#define NAVY            0x000080
#define TEAL            0x008080
#define OLIVE           0x808000
#define MAROON          0x800000
#define SILVER          0xC0C0C0
#define GRAY            0x808080
#define GOLD            0xFFD700
#define LIGHT_BLUE      0xADD8E6
#define LIGHT_GREEN     0x90EE90
#define LIGHT_CORAL     0xF08080
#define LIGHT_YELLOW    0xFFFFE0
#define LIGHT_CYAN      0xE0FFFF
#define LIGHT_MAGENTA   0xFF77FF
#define LIGHT_ORANGE    0xFFDAB9
#define LIGHT_PURPLE    0xE6E6FA
#define LIGHT_PINK      0xFFB6C1
#define LIGHT_BROWN     0xD2B48C


// KEYCODES
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_MOVE MotionNotify

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
	int		mandelbrot;
	int		julia;
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
int julia_track(int x, int y, t_fractol *fract);

// inits.c
void	init_fractol(t_fractol *fractol, int argc);
void	init_mlx(t_fractol *fractol);

// main.c
int		main(int argc, char **argv);

//tools.c
void	color_pixel(t_fractol *fractol, int x, int y, int color);
int		clean_exit(t_fractol *fractol);
double	ft_atod(char *s);
int error_handling(int argc, char **argv, t_fractol *fractol);

#endif
