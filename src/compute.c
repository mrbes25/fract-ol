#include "../fractol.h"

void	compute_mandelbrot(t_fractol *fractol)
{
	int		i;
	double	x_temp;

	fractol->name = "mandelbrot";
	i = 0;
	fractol->zx = 0.0;
	fractol->zy = 0.0;
	fractol->cx = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->cy = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (++i < fractol->max_iterations)
	{
		x_temp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2. * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = x_temp;
		if (fractol->zx * fractol->zx + fractol->zy
			* fractol->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		color_pixel(fractol, fractol->x, fractol->y, BLACK);
	else
		color_pixel(fractol, fractol->x, fractol->y, (fractol->color
				* i));
}

void	compute_julia(t_fractol *fractol)
{
	int		i;
	double	tmp;
	int colors[] = {BLACK, WHITE, RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA,
	ORANGE, PURPLE, PINK, BROWN, LIME, NAVY, TEAL, OLIVE, MAROON, SILVER,
	GRAY, GOLD, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CORAL, LIGHT_YELLOW,
	LIGHT_CYAN, LIGHT_MAGENTA, LIGHT_ORANGE, LIGHT_PURPLE, LIGHT_PINK, LIGHT_BROWN};

	fractol->name = "julia";
	fractol->zx = fractol->x / fractol->zoom + fractol->offset_x;
	fractol->zy = fractol->y / fractol->zoom + fractol->offset_y;
	i = 0;
	while (++i < fractol->max_iterations)
	{
		tmp = fractol->zx;
		fractol->zx = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2 * fractol->zy * tmp + fractol->cy;
		if (fractol->zx * fractol->zx + fractol->zy
			* fractol->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		color_pixel(fractol, fractol->x, fractol->y, BLACK);
	else
		color_pixel(fractol, fractol->x, fractol->y, colors[i % (sizeof(colors) / sizeof(int))]);
}
